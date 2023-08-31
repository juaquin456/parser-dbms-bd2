// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 34 "parser.yy"

    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <vector>
    #include "driver.hpp"

    #undef yylex
    #define yylex sc.yylex

#line 57 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 149 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

  /// Build a parser object.
  parser::parser (scanner &sc_yyarg, driver &dr_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      sc (sc_yyarg),
      dr (dr_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.copy< column_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.copy< std::pair<int, int> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        value.copy< std::vector<column_t*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        value.copy< std::vector<std::string>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.move< column_t* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.move< std::pair<int, int> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        value.move< std::vector<column_t*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        value.move< std::vector<std::string>* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.YY_MOVE_OR_COPY< column_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.YY_MOVE_OR_COPY< std::pair<int, int> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        value.YY_MOVE_OR_COPY< std::vector<column_t*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        value.YY_MOVE_OR_COPY< std::vector<std::string>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.move< column_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.move< std::pair<int, int> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        value.move< std::vector<column_t*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        value.move< std::vector<std::string>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.copy< column_t* > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.copy< std::pair<int, int> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        value.copy< std::vector<column_t*> > (that.value);
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        value.copy< std::vector<std::string>* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.move< column_t* > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (that.value);
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.move< std::pair<int, int> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        value.move< std::vector<column_t*> > (that.value);
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        value.move< std::vector<std::string>* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        yylhs.value.emplace< column_t* > ();
        break;

      case symbol_kind::S_NUM: // NUM
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_TYPE: // TYPE
        yylhs.value.emplace< std::pair<int, int> > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_CREATE_LIST: // CREATE_LIST
        yylhs.value.emplace< std::vector<column_t*> > ();
        break;

      case symbol_kind::S_COLUMNS: // COLUMNS
        yylhs.value.emplace< std::vector<std::string>* > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // $@1: %empty
#line 64 "parser.yy"
                                    {dr.exec();}
#line 814 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 19: // $@2: %empty
#line 77 "parser.yy"
                                    {if (yystack_[0].value.as < std::string > ().size() > 64) yy::parser::error(yystack_[0].location, "Table name is too large");}
#line 820 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 20: // CREATE_TYPE: CREATE TABLE ID $@2 PI CREATE_LIST PD
#line 77 "parser.yy"
                                                                                                                              {dr.createTable(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<column_t*> > ());}
#line 826 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 21: // SELECT_TYPE: SELECT COLUMNS FROM ID CONDITIONALS
#line 78 "parser.yy"
                                                        {dr.select(yystack_[1].value.as < std::string > (), yystack_[3].value.as < std::vector<std::string>* > ());}
#line 832 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 22: // TYPE: INT
#line 81 "parser.yy"
                        {yylhs.value.as < std::pair<int, int> > ().first = 0;}
#line 838 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 23: // TYPE: DOUBLE
#line 81 "parser.yy"
                                                {yylhs.value.as < std::pair<int, int> > ().first = 1;}
#line 844 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 24: // TYPE: CHAR
#line 81 "parser.yy"
                                                                       {yylhs.value.as < std::pair<int, int> > ().first = 2; yylhs.value.as < std::pair<int, int> > ().second = 1;}
#line 850 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 25: // TYPE: CHAR PI NUM PD
#line 81 "parser.yy"
                                                                                                                       {yylhs.value.as < std::pair<int, int> > ().first = 2; yylhs.value.as < std::pair<int, int> > ().second = yystack_[1].value.as < int > ();}
#line 856 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 26: // TYPE: BOOL
#line 81 "parser.yy"
                                                                                                                                                             {yylhs.value.as < std::pair<int, int> > ().first = 3;}
#line 862 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 27: // COLUMNS: COLUMNS SEP ID
#line 84 "parser.yy"
                                   {yystack_[2].value.as < std::vector<std::string>* > ()->push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::vector<std::string>* > () = yystack_[2].value.as < std::vector<std::string>* > ();}
#line 868 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 28: // COLUMNS: ID
#line 84 "parser.yy"
                                                                      {yylhs.value.as < std::vector<std::string>* > () = new std::vector<std::string>{yystack_[0].value.as < std::string > ()};}
#line 874 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 42: // CREATE_LIST: CREATE_LIST SEP CREATE_UNIT
#line 103 "parser.yy"
                                                {yylhs.value.as < std::vector<column_t*> > () = yystack_[2].value.as < std::vector<column_t*> > (); yylhs.value.as < std::vector<column_t*> > ().push_back(yystack_[0].value.as < column_t* > ());}
#line 880 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 43: // CREATE_LIST: CREATE_UNIT
#line 103 "parser.yy"
                                                                                           {yylhs.value.as < std::vector<column_t*> > ().push_back(yystack_[0].value.as < column_t* > ());}
#line 886 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 44: // CREATE_UNIT: ID TYPE
#line 104 "parser.yy"
                            { yylhs.value.as < column_t* > () = new column_t(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::pair<int, int> > (), 0);}
#line 892 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 45: // CREATE_UNIT: ID TYPE PK
#line 105 "parser.yy"
                                 { yylhs.value.as < column_t* > () = new column_t(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::pair<int, int> > (), 1);}
#line 898 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;


#line 902 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -40;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       9,    -6,   -18,    16,    10,     8,    29,    34,   -40,   -40,
     -40,   -40,   -40,    12,    27,    13,   -40,     0,    14,   -40,
     -40,    32,    17,    35,    18,    20,   -40,     9,    24,    36,
      -1,   -40,   -22,   -40,   -40,    35,    30,   -40,     7,     1,
      17,   -40,   -40,    37,   -40,   -40,    33,    40,    41,   -40,
     -40,   -40,    26,    54,    38,   -40,   -40,   -40,     1,     4,
     -22,   -22,    -3,    -2,   -40,     7,   -40,   -40,    42,   -40,
      41,   -40,   -40,   -40,    43,   -40,    39,    26,   -40,   -40,
       1,    28,   -40,   -40,   -40,    44,   -40
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,     0,     0,     0,    28,     0,     0,     1,
       3,     0,     0,    29,     0,     0,    19,     2,     0,     0,
      29,    40,     0,    17,    27,    29,     0,     4,     0,     0,
       0,    18,    10,    12,    11,    13,     0,    30,    32,    34,
      36,    21,     0,    15,     0,    12,    41,    39,     0,     0,
       0,     0,     0,     0,    43,     0,    16,    35,    12,    38,
      31,    33,    22,    23,    24,    26,    44,     0,    20,    14,
       0,     0,    45,    42,    37,     0,    25
  };

  const signed char
  parser::yypgoto_[] =
  {
     -40,    45,   -40,   -40,   -37,   -39,     3,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -24,   -40,     2,     5,   -40,
     -40,    31,   -40,   -13
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     6,    27,     7,    45,    46,    54,     8,     9,    10,
      11,    36,    12,    76,    17,    33,    47,    48,    49,    50,
      30,    31,    63,    64
  };

  const signed char
  parser::yytable_[] =
  {
      56,    53,    77,    40,    24,    13,    41,    42,    43,    44,
      25,    51,    14,    32,     1,     2,     3,     4,     5,    67,
      69,    78,    72,    73,    74,    75,    15,    18,    53,    19,
      42,    55,    44,    42,    68,    44,    42,    20,    44,    22,
      16,    84,    21,    23,    26,    28,    38,    29,    34,    32,
      35,    59,    52,    39,    58,    60,    62,    61,    65,    85,
      80,    66,    70,    82,    83,    81,    71,    86,    79,     0,
       0,    57,    37
  };

  const signed char
  parser::yycheck_[] =
  {
      39,    38,     4,     4,     4,    11,    30,    29,    30,    31,
      10,    35,    30,    14,     5,     6,     7,     8,     9,    58,
      59,    23,    25,    26,    27,    28,    10,    19,    65,     0,
      29,    30,    31,    29,    30,    31,    29,     3,    31,    12,
      30,    80,    30,    30,    30,    13,    22,    30,    30,    14,
      30,    18,    22,    17,    17,    15,    30,    16,     4,    31,
      18,    23,    60,    24,    77,    22,    61,    23,    65,    -1,
      -1,    40,    27
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    33,    35,    39,    40,
      41,    42,    44,    11,    30,    10,    30,    46,    19,     0,
       3,    30,    12,    30,     4,    10,    30,    34,    13,    30,
      52,    53,    14,    47,    30,    30,    43,    33,    22,    17,
       4,    47,    29,    30,    31,    36,    37,    48,    49,    50,
      51,    47,    22,    36,    38,    30,    37,    53,    17,    18,
      15,    16,    30,    54,    55,     4,    23,    37,    30,    37,
      49,    50,    25,    26,    27,    28,    45,     4,    23,    38,
      18,    22,    24,    55,    37,    31,    23
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    32,    33,    34,    33,    35,    35,    35,    35,    35,
      36,    36,    37,    37,    38,    38,    39,    40,    41,    43,
      42,    44,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    55
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     7,     4,     5,     0,
       7,     5,     1,     1,     1,     4,     1,     3,     1,     0,
       2,     3,     1,     3,     1,     3,     1,     5,     3,     3,
       1,     3,     3,     1,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ENDL", "SEP",
  "INSERT", "UPDATE", "DELETE", "SELECT", "CREATE", "FROM", "INTO", "SET",
  "VALUES", "WHERE", "AND", "OR", "EQUAL", "RANGE_OPERATOR", "TABLE",
  "INDEX", "COLUMN", "PI", "PD", "PK", "INT", "DOUBLE", "CHAR", "BOOL",
  "STRING", "ID", "NUM", "$accept", "PROGRAM", "$@1", "SENTENCE",
  "INPLACE_VALUE", "VALUE", "PARAMS", "INSERT_TYPE", "DELETE_TYPE",
  "UPDATE_TYPE", "CREATE_TYPE", "$@2", "SELECT_TYPE", "TYPE", "COLUMNS",
  "CONDITIONALS", "CONDITION_LIST", "FACTOR_CONDITION", "CONDITION",
  "RANGE_CONDITION", "SET_LIST", "SET_UNIT", "CREATE_LIST", "CREATE_UNIT", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    63,    63,    64,    64,    66,    66,    66,    66,    66,
      68,    68,    69,    69,    70,    70,    74,    75,    76,    77,
      77,    78,    81,    81,    81,    81,    81,    84,    84,    87,
      88,    90,    90,    91,    91,    93,    94,    95,    96,    99,
      99,   100,   103,   103,   104,   105
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
    };
    // Last valid token kind.
    const int code_max = 286;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1312 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

#line 106 "parser.yy"


void yy::parser::error(const location_type &l, const std::string &message){
    std::cerr << "Error: " << message << " at "<<l.end<< "\n";
}
