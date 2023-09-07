%debug
%language "c++"
%defines
%define api.parser.class {parser}

%code requires{
    #include <string>
    #include <utility>

    #include <list>
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

        template<typename T>
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
        std::string value;

        condition_t() = default;
        condition_t(const std::string& column, Comp comparator, const std::string& value):
            column(column), c(comparator), value(value) {}
        condition_t(const condition_t& another) {
            this->c = another.c;
            this->column = another.column;
            this->value = another.value;
        }

        condition_t& operator=(const condition_t& another) {
            this->c = another.c;
            this->column = another.column;
            this->value = another.value;
            return *this;
        }
    };


    class SqlParser;
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
%parse-param {SqlParser &dr}

%code {
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <vector>
    #include "SqlParser.hpp"

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

%type <std::string> INPLACE_VALUE
%type <condition_t> CONDITION
%type <std::list<std::list<condition_t>>> CONDITION_LIST
%type <std::list<condition_t>> FACTOR_CONDITION
%type <std::list<std::list<condition_t>>> CONDITIONALS
%locations

%%

PROGRAM:            /*  */
                    | SENTENCE ENDL {dr.exec();} PROGRAM;

SENTENCE:           INSERT_TYPE | DELETE_TYPE | UPDATE_TYPE | CREATE_TYPE | SELECT_TYPE;

INPLACE_VALUE:      STRING      {$$ = $1;} 
                    | NUM       {$$ = std::to_string($1);} 
                    | FLOATING  {$$ = std::to_string($1);};
VALUE:              ID | INPLACE_VALUE;
PARAMS:             INPLACE_VALUE SEP PARAMS | INPLACE_VALUE;
RANGE_OPERATOR:     GE {$$ = GE;}| G {$$ = G;}| LE {$$ = LE;}| L {$$ = L;};
/* SENTECES TYPE */

INSERT_TYPE:        INSERT INTO ID VALUES PI PARAMS PD;
DELETE_TYPE:        DELETE FROM ID CONDITIONALS;
UPDATE_TYPE:        UPDATE ID SET SET_LIST CONDITIONALS;
CREATE_TYPE:        CREATE TABLE ID PI CREATE_LIST PD {dr.createTable($3, $5);}
SELECT_TYPE:        SELECT COLUMNS FROM ID {dr.checkTableName($4);} CONDITIONALS {dr.select($4, $2, $6);};

/* TYPES */
TYPE:               INT {$$ = Type(Type::Numeric, sizeof(int));}| DOUBLE {$$ = Type(Type::Floating, sizeof(double));} | CHAR {$$ = Type(Type::Char, 1);} | CHAR PI NUM PD {$$ = Type(Type::Char, $3);}| BOOL {$$ = Type(Type::Bool, sizeof(bool));}

/* COLUMN NAMES */
COLUMNS:            COLUMNS SEP ID {$1->push_back($3); $$ = $1;} | ID {$$ = new std::vector<std::string>{$1};}

/* CONDITIONS */
CONDITIONALS:       /*  */ {}
                    | WHERE CONDITION_LIST {$$ = $2;};

CONDITION_LIST:     CONDITION_LIST OR FACTOR_CONDITION {$$ = $1; $$.push_front($3);} | FACTOR_CONDITION {$$.push_front($1);}
FACTOR_CONDITION:   FACTOR_CONDITION AND CONDITION {$$ = $1; $$.push_front($3);} | CONDITION {$$.push_front($1);};
CONDITION:          ID EQUAL INPLACE_VALUE {$$ = condition_t($1, EQUAL, $3);}
                    | ID RANGE_OPERATOR INPLACE_VALUE {$$ = condition_t($1, $2, $3);}

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
