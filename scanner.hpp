#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__ 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.tab.hh"
#include "location.hh"

class scanner: public yyFlexLexer {
public:
    scanner(std::istream *in): yyFlexLexer(in){
        loc = new yy::parser::location_type();
    };

    using FlexLexer::yylex;

    virtual int yylex(yy::parser::semantic_type * const lval, yy::parser::location_type * location);

private:
    yy::parser::semantic_type *yylval = nullptr;
    yy::parser::location_type *loc = nullptr;
};

#endif