%debug
%language "c++"
%defines
%define api.parser.class {parser}

%code requires{
    #include <string>
    #include <cstring>
    #include <utility>


    struct Type {        
        enum Enum {
            Bool,
            Numeric,
            Floating,
            Char
        };

        size_t size;
        Enum value;

        Type() = default;
        Type(Enum e, const size_t& _size): size(_size), value(e) {}
        Type(const Type& t) {
            this->size = t.size;
            this->value = t.value;
        }
        Type& operator=(const Type& t) {
            this->size = t.size;
            this->value = t.value;
            return *this;
        }
    };

    struct column_t {
        std::string name;
        Type type;
        bool is_pk;
        column_t(const std::string& name, const Type& type, const bool& is_pk): name(name), type(type), is_pk(is_pk) {}
    };

    struct Inplace {
        char* data;
        Type type;

        Inplace() = default;

        template<typename T, typename = std::enable_if_t<!std::is_same<T, char*>::value>>
        Inplace(T value, const Type& _type) {
            this->data = new char[_type.size];
            memcpy(this->data, value, _type.size);
            this->type = _type;
        }
        Inplace(const Inplace& another) {
            this->data = another.data;
            this->type = another.type;
        }
    };
    
    enum Comp {
        EQUAL,
        GE,
        LE,
        G,
        L
    };

    struct condition_t {
        Comp c;
        std::string column;
        Inplace value;

        condition_t() = default;
        condition_t(const std::string& column, Comp comparator, const Inplace& value):
            column(column), c(comparator), value(value) {}
    };


    class driver;
    class scanner;

    #define YYERROR_VERBOSE 1
    #ifndef YY_NULLPTR
    #if defined __cplusplus && 201103L <= __cplusplus
    #define YY_NULLPTR nullptr
    #else
    #define YY_NULLPTR 0
    #endif
    #endif

}

%parse-param {scanner &sc}
%parse-param {driver &dr}

%code {
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <vector>
    #include "driver.hpp"

    #undef yylex
    #define yylex sc.yylex
}

%define api.value.type variant
%define parse.assert

%token ENDL SEP INSERT UPDATE DELETE SELECT CREATE FROM INTO SET VALUES WHERE AND OR EQUAL TABLE INDEX COLUMN PI PD PK
%token INT DOUBLE CHAR BOOL
%token GE G LE L
%token <std::string> ID
%token <std::string> STRING
%token <int> NUM
%token <double> FLOATING

%type <Comp> RANGE_OPERATOR

%type <std::vector<std::string>*> COLUMNS

%type <std::vector<column_t*>> CREATE_LIST
%type <column_t*> CREATE_UNIT
%type <Type> TYPE

%type <Inplace> INPLACE_VALUE
%type <condition_t*> CONDITION
%type <condition_t*> CONDITION_LIST
%type <condition_t*> CONDITIONALS
%locations

%%

PROGRAM:            /*  */
                    | SENTENCE ENDL {dr.exec();} PROGRAM;

SENTENCE:           INSERT_TYPE | DELETE_TYPE | UPDATE_TYPE | CREATE_TYPE | SELECT_TYPE;

INPLACE_VALUE:      STRING      {$$ = Inplace($1.data(), Type(Type::Char, $1.length()));} 
                    | NUM       {$$ = Inplace(&$1, Type(Type::Numeric, sizeof(int)));} 
                    | FLOATING  {$$ = Inplace(&$1, Type(Type::Floating, sizeof(double)));};
VALUE:              ID | INPLACE_VALUE;
PARAMS:             INPLACE_VALUE SEP PARAMS | INPLACE_VALUE;
RANGE_OPERATOR:     GE {$$ = GE;}| G {$$ = G;}| LE {$$ = LE;}| L {$$ = L;};
/* SENTECES TYPE */

INSERT_TYPE:        INSERT INTO ID VALUES PI PARAMS PD;
DELETE_TYPE:        DELETE FROM ID CONDITIONALS;
UPDATE_TYPE:        UPDATE ID SET SET_LIST CONDITIONALS;
CREATE_TYPE:        CREATE TABLE ID {if ($3.size() > 64) yy::parser::error(@3, "Table name is too large");} PI CREATE_LIST PD {dr.createTable($3, $6);}
SELECT_TYPE:        SELECT COLUMNS FROM ID CONDITIONALS {dr.select($4, $2, $5);}

/* TYPES */
TYPE:               INT {$$ = Type(Type::Numeric, sizeof(int));}| DOUBLE {$$ = Type(Type::Floating, sizeof(double));} | CHAR {$$ = Type(Type::Char, 1);} | CHAR PI NUM PD {$$ = Type(Type::Char, $3);}| BOOL {$$ = Type(Type::Bool, sizeof(bool));}

/* COLUMN NAMES */
COLUMNS:            COLUMNS SEP ID {$1->push_back($3); $$ = $1;} | ID {$$ = new std::vector<std::string>{$1};}

/* CONDITIONS */
CONDITIONALS:       /*  */
                    | WHERE CONDITION_LIST {$$ = $2;};

/* CONDITION_LIST:     CONDITION_LIST AND FACTOR_CONDITION | FACTOR_CONDITION;
FACTOR_CONDITION:   FACTOR_CONDITION OR CONDITION | CONDITION;
 */
CONDITION_LIST:     CONDITION {$$ = $1;}
CONDITION:          ID EQUAL INPLACE_VALUE {$$ = new condition_t($1, EQUAL, $3);}
                    | ID RANGE_OPERATOR INPLACE_VALUE {$$ = new condition_t($1, $2, $3);}

/* UPDATE PARAMETERS */
SET_LIST:           SET_LIST SEP SET_UNIT | SET_UNIT;
SET_UNIT:           ID EQUAL VALUE;

/* CREATE TABLE PARAMETERS */
CREATE_LIST:        CREATE_LIST SEP CREATE_UNIT {$$ = $1; $$.push_back($3);} | CREATE_UNIT {$$.push_back($1);}; // TODO: Optimize copy
CREATE_UNIT:        ID TYPE { $$ = new column_t($1, $2, 0);}
                    | ID TYPE PK { $$ = new column_t($1, $2, 1);}
%%

void yy::parser::error(const location_type &l, const std::string &message){
    std::cerr << "Error: " << message << " at "<<l.end<< "\n";
}