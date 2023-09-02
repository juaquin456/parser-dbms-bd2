%debug
%language "c++"
%defines
%define api.parser.class {parser}

%code requires{
    #include <string>
    #include <utility>

    struct column_t {
        std::string name;
        std::pair<char, int> type;
        bool is_pk;
        column_t(const std::string& name, const std::pair<char, int>& type, const bool& is_pk): name(name), type(type), is_pk(is_pk) {}
    };

    struct condition_t {
        std::string column_name;
        std::string op;
        // TODO
    }

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

%token ENDL SEP INSERT UPDATE DELETE SELECT CREATE FROM INTO SET VALUES WHERE AND OR EQUAL RANGE_OPERATOR TABLE INDEX COLUMN PI PD PK
%token INT DOUBLE CHAR BOOL
%token <std::string> STRING
%token <std::string> ID
%token <int> NUM
%token <double> FLOATING

%type <std::vector<std::string>*> COLUMNS

%type <std::vector<column_t*>> CREATE_LIST
%type <column_t*> CREATE_UNIT
%type <std::pair<char, int>> TYPE
%locations

%%

PROGRAM:            /*  */
                    | SENTENCE ENDL {dr.exec();} PROGRAM;

SENTENCE:           INSERT_TYPE | DELETE_TYPE | UPDATE_TYPE | CREATE_TYPE | SELECT_TYPE;

INPLACE_VALUE:      STRING | NUM | FLOATING;
VALUE:              ID | INPLACE_VALUE;
PARAMS:             INPLACE_VALUE SEP PARAMS | INPLACE_VALUE;

/* SENTECES TYPE */

INSERT_TYPE:        INSERT INTO ID VALUES PI PARAMS PD;
DELETE_TYPE:        DELETE FROM ID CONDITIONALS;
UPDATE_TYPE:        UPDATE ID SET SET_LIST CONDITIONALS;
CREATE_TYPE:        CREATE TABLE ID {if ($3.size() > 64) yy::parser::error(@3, "Table name is too large");} PI CREATE_LIST PD {dr.createTable($3, $6);}
SELECT_TYPE:        SELECT COLUMNS FROM ID CONDITIONALS {dr.select($4, $2);}

/* TYPES */
TYPE:               INT {$$.first = 0;}| DOUBLE {$$.first = 1;} | CHAR {$$.first = 2; $$.second = 1;} | CHAR PI NUM PD {$$.first = 2; $$.second = $3;}| BOOL {$$.first = 3;}

/* COLUMN NAMES */
COLUMNS:            COLUMNS SEP ID {$1->push_back($3); $$ = $1;} | ID {$$ = new std::vector<std::string>{$1};}

/* CONDITIONS */
CONDITIONALS:       /*  */
                    | WHERE CONDITION_LIST;

CONDITION_LIST:     CONDITION_LIST AND FACTOR_CONDITION | FACTOR_CONDITION;
FACTOR_CONDITION:   FACTOR_CONDITION OR CONDITION | CONDITION;

CONDITION:          ID EQUAL VALUE
                    | ID RANGE_OPERATOR VALUE
                    | VALUE RANGE_OPERATOR ID ;

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