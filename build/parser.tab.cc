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
#line 61 "parser.yy"
                                    {dr.exec();}
#line 786 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 18: // $@2: %empty
#line 74 "parser.yy"
                                    {if (yystack_[0].value.as < std::string > ().size() > 64) yy::parser::error(yystack_[0].location, "Table name is too large");}
#line 792 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 19: // CREATE_TYPE: CREATE TABLE ID $@2 PI CREATE_LIST PD
#line 74 "parser.yy"
                                                                                                                              {dr.createTable(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<column_t*> > ());}
#line 798 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 20: // TYPE: INT
#line 77 "parser.yy"
                        {yylhs.value.as < std::pair<int, int> > ().first = 0;}
#line 804 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 21: // TYPE: DOUBLE
#line 77 "parser.yy"
                                                {yylhs.value.as < std::pair<int, int> > ().first = 1;}
#line 810 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 22: // TYPE: CHAR
#line 77 "parser.yy"
                                                                       {yylhs.value.as < std::pair<int, int> > ().first = 2; yylhs.value.as < std::pair<int, int> > ().second = 1;}
#line 816 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 23: // TYPE: CHAR PI NUM PD
#line 77 "parser.yy"
                                                                                                                       {yylhs.value.as < std::pair<int, int> > ().first = 2; yylhs.value.as < std::pair<int, int> > ().second = yystack_[1].value.as < int > ();}
#line 822 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 24: // TYPE: BOOL
#line 77 "parser.yy"
                                                                                                                                                             {yylhs.value.as < std::pair<int, int> > ().first = 3;}
#line 828 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 25: // TYPE: DATE
#line 77 "parser.yy"
                                                                                                                                                                                    {yylhs.value.as < std::pair<int, int> > ().first = 4;}
#line 834 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 39: // CREATE_LIST: CREATE_LIST SEP CREATE_UNIT
#line 96 "parser.yy"
                                                {yylhs.value.as < std::vector<column_t*> > () = yystack_[2].value.as < std::vector<column_t*> > (); yylhs.value.as < std::vector<column_t*> > ().push_back(yystack_[0].value.as < column_t* > ());}
#line 840 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 40: // CREATE_LIST: CREATE_UNIT
#line 96 "parser.yy"
                                                                                           {yylhs.value.as < std::vector<column_t*> > ().push_back(yystack_[0].value.as < column_t* > ());}
#line 846 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 41: // CREATE_UNIT: ID TYPE
#line 97 "parser.yy"
                            { yylhs.value.as < column_t* > () = new column_t(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::pair<int, int> > (), 0);}
#line 852 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 42: // CREATE_UNIT: ID TYPE PK
#line 98 "parser.yy"
                                 { yylhs.value.as < column_t* > () = new column_t(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::pair<int, int> > (), 1);}
#line 858 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;


#line 862 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

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









  const signed char parser::yypact_ninf_ = -32;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       5,     9,   -22,    15,    10,    33,    31,   -32,   -32,   -32,
     -32,     4,    24,     6,     7,   -32,   -32,    26,    11,    29,
     -32,     5,    18,    27,    -1,   -32,   -15,   -32,    23,   -32,
      -4,    -8,    11,   -32,   -32,    30,   -32,   -32,    28,    34,
      32,   -32,   -32,    19,    47,    35,   -32,   -32,   -32,    -8,
       0,   -15,   -15,   -21,    -2,   -32,    -4,   -32,   -32,    36,
     -32,    32,   -32,   -32,   -32,    37,   -32,   -32,    38,    19,
     -32,   -32,    -8,    20,   -32,   -32,   -32,    40,   -32
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     1,     3,     0,     0,    26,
      18,     2,     0,     0,    26,    37,     0,    16,     0,     4,
       0,     0,     0,    17,     9,    11,    10,    12,     0,    27,
      29,    31,    33,     0,    14,     0,    11,    38,    36,     0,
       0,     0,     0,     0,     0,    40,     0,    15,    32,    11,
      35,    28,    30,    20,    21,    22,    24,    25,    41,     0,
      19,    13,     0,     0,    42,    39,    34,     0,    23
  };

  const signed char
  parser::yypgoto_[] =
  {
     -32,    39,   -32,   -32,   -29,   -31,    -3,   -32,   -32,   -32,
     -32,   -32,   -32,    41,   -32,    13,     3,   -32,   -32,    25,
     -32,   -13
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     5,    21,     6,    37,    38,    45,     7,     8,     9,
      10,    28,    68,    27,    39,    40,    41,    42,    24,    25,
      54,    55
  };

  const signed char
  parser::yytable_[] =
  {
      47,    44,    69,    32,    63,    64,    65,    66,    67,    12,
       1,     2,     3,    26,     4,    34,    35,    36,    58,    60,
      11,    70,    34,    46,    36,    13,    34,    44,    36,    14,
      34,    59,    36,    15,    16,    17,    18,    19,    20,    22,
      30,    76,    23,    26,    31,    43,    50,    49,    52,    51,
      53,    56,    77,    71,    72,    62,    75,    48,    57,    73,
      29,     0,    74,    78,    61,    33
  };

  const signed char
  parser::yycheck_[] =
  {
      31,    30,     4,     4,    25,    26,    27,    28,    29,    31,
       5,     6,     7,    14,     9,    30,    31,    32,    49,    50,
      11,    23,    30,    31,    32,    10,    30,    56,    32,    19,
      30,    31,    32,     0,     3,    31,    12,    31,    31,    13,
      22,    72,    31,    14,    17,    22,    18,    17,    16,    15,
      31,     4,    32,    56,    18,    52,    69,    32,    23,    22,
      21,    -1,    24,    23,    51,    24
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     9,    34,    36,    40,    41,    42,
      43,    11,    31,    10,    19,     0,     3,    31,    12,    31,
      31,    35,    13,    31,    51,    52,    14,    46,    44,    34,
      22,    17,     4,    46,    30,    31,    32,    37,    38,    47,
      48,    49,    50,    22,    37,    39,    31,    38,    52,    17,
      18,    15,    16,    31,    53,    54,     4,    23,    38,    31,
      38,    48,    49,    25,    26,    27,    28,    29,    45,     4,
      23,    39,    18,    22,    24,    54,    38,    32,    23
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    33,    34,    35,    34,    36,    36,    36,    36,    37,
      37,    38,    38,    39,    39,    40,    41,    42,    44,    43,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    53,
      53,    54,    54
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     7,     4,     5,     0,     7,
       1,     1,     1,     4,     1,     1,     0,     2,     3,     1,
       3,     1,     3,     1,     5,     3,     3,     1,     3,     3,
       1,     2,     3
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
  "DATE", "STRING", "ID", "NUM", "$accept", "PROGRAM", "$@1", "SENTENCE",
  "INPLACE_VALUE", "VALUE", "PARAMS", "INSERT_TYPE", "DELETE_TYPE",
  "UPDATE_TYPE", "CREATE_TYPE", "$@2", "TYPE", "CONDITIONALS",
  "CONDITION_LIST", "FACTOR_CONDITION", "CONDITION", "RANGE_CONDITION",
  "SET_LIST", "SET_UNIT", "CREATE_LIST", "CREATE_UNIT", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    60,    60,    61,    61,    63,    63,    63,    63,    65,
      65,    66,    66,    67,    67,    71,    72,    73,    74,    74,
      77,    77,    77,    77,    77,    77,    80,    81,    83,    83,
      84,    84,    86,    87,    88,    89,    92,    92,    93,    96,
      96,    97,    98
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
      25,    26,    27,    28,    29,    30,    31,    32
    };
    // Last valid token kind.
    const int code_max = 287;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1267 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

#line 99 "parser.yy"


void yy::parser::error(const location_type &l, const std::string &message){
    std::cerr << "Error: " << message << " at "<<l.end<< "\n";
}
