%debug
%language "c++"
%defines
%define api.parser.class {parser}

%code requires{
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
    #include "driver.hpp"

    #undef yylex
    #define yylex sc.yylex
}

%define api.value.type variant
%define parse.assert

%token ENDL SEP INSERT UPDATE DELETE SELECT CREATE FROM INTO SET VALUES WHERE AND OR EQUAL RANGE_OPERATOR TABLE INDEX COLUMN PI PD
%token INT DOUBLE CHAR
%token <std::string> STRING
%token <std::string> ID
%token <int> NUM
%locations

%%

PROGRAM:            /*  */
                    | SENTENCE ENDL {dr.exec();} PROGRAM;

SENTENCE:           INSERT_TYPE | DELETE_TYPE | UPDATE_TYPE | CREATE_TYPE;

INPLACE_VALUE:          STRING | NUM;
VALUE:               ID | INPLACE_VALUE;
PARAMS:         INPLACE_VALUE SEP PARAMS | INPLACE_VALUE;

/* SENTECES TYPE */

INSERT_TYPE:        INSERT INTO ID VALUES PI PARAMS PD {dr.setTableName($3);};
DELETE_TYPE:        DELETE FROM ID CONDITIONALS {dr.setTableName($3);};
UPDATE_TYPE:        UPDATE ID SET SET_LIST CONDITIONALS {dr.setTableName($2);};
CREATE_TYPE:        CREATE TABLE ID PI CREATE_LIST PD {dr.setTableName($3);};

/* TYPES */
TYPE:               INT | DOUBLE | CHAR | CHAR PI NUM PD;

/* CONDITIONS */
CONDITIONALS:       /*  */
                    | WHERE CONDITION_LIST;

CONDITION_LIST:     CONDITION_LIST AND FACTOR_CONDITION | FACTOR_CONDITION;
FACTOR_CONDITION:   FACTOR_CONDITION OR CONDITION | CONDITION;

CONDITION:          ID EQUAL VALUE
                    | RANGE_CONDITION;
RANGE_CONDITION:    VALUE RANGE_OPERATOR ID RANGE_OPERATOR VALUE
                    | VALUE RANGE_OPERATOR VALUE;

/* UPDATE PARAMETERS */
SET_LIST:           SET_LIST SEP SET_UNIT | SET_UNIT;
SET_UNIT:           ID EQUAL VALUE;

/* CREATE TABLE PARAMETERS */
CREATE_LIST:        CREATE_LIST SEP CREATE_UNIT | CREATE_UNIT;
CREATE_UNIT:        ID TYPE; /* TODO: ADD COLUMN CONSTRAINT (PK, NULLABLE, ...) */
%%

void yy::parser::error(const location_type &l, const std::string &message){
    std::cerr << "Error: " << message << " at "<<l.end<< "\n";
}