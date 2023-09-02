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
#line 97 "parser.yy"

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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        value.copy< Comp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        value.copy< Inplace > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.copy< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.copy< column_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        value.copy< condition_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        value.move< Comp > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        value.move< Inplace > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.move< Type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.move< column_t* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        value.move< condition_t* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        value.YY_MOVE_OR_COPY< Comp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        value.YY_MOVE_OR_COPY< Inplace > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.YY_MOVE_OR_COPY< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.YY_MOVE_OR_COPY< column_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        value.YY_MOVE_OR_COPY< condition_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        value.move< Comp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        value.move< Inplace > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.move< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.move< column_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        value.move< condition_t* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        value.copy< Comp > (that.value);
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        value.copy< Inplace > (that.value);
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.copy< Type > (that.value);
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.copy< column_t* > (that.value);
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        value.copy< condition_t* > (that.value);
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        value.move< Comp > (that.value);
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        value.move< Inplace > (that.value);
        break;

      case symbol_kind::S_TYPE: // TYPE
        value.move< Type > (that.value);
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        value.move< column_t* > (that.value);
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        value.move< condition_t* > (that.value);
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        value.move< double > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_RANGE_OPERATOR: // RANGE_OPERATOR
        yylhs.value.emplace< Comp > ();
        break;

      case symbol_kind::S_INPLACE_VALUE: // INPLACE_VALUE
        yylhs.value.emplace< Inplace > ();
        break;

      case symbol_kind::S_TYPE: // TYPE
        yylhs.value.emplace< Type > ();
        break;

      case symbol_kind::S_CREATE_UNIT: // CREATE_UNIT
        yylhs.value.emplace< column_t* > ();
        break;

      case symbol_kind::S_CONDITIONALS: // CONDITIONALS
      case symbol_kind::S_CONDITION_LIST: // CONDITION_LIST
      case symbol_kind::S_CONDITION: // CONDITION
        yylhs.value.emplace< condition_t* > ();
        break;

      case symbol_kind::S_FLOATING: // FLOATING
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_NUM: // NUM
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
#line 136 "parser.yy"
                                    {dr.exec();}
#line 940 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 10: // INPLACE_VALUE: STRING
#line 140 "parser.yy"
                                {yylhs.value.as < Inplace > () = Inplace(yystack_[0].value.as < std::string > ().data(), Type(Type::Char, yystack_[0].value.as < std::string > ().length()));}
#line 946 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 11: // INPLACE_VALUE: NUM
#line 141 "parser.yy"
                                {yylhs.value.as < Inplace > () = Inplace(&yystack_[0].value.as < int > (), Type(Type::Numeric, sizeof(int)));}
#line 952 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 12: // INPLACE_VALUE: FLOATING
#line 142 "parser.yy"
                                {yylhs.value.as < Inplace > () = Inplace(&yystack_[0].value.as < double > (), Type(Type::Floating, sizeof(double)));}
#line 958 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 17: // RANGE_OPERATOR: GE
#line 145 "parser.yy"
                       {yylhs.value.as < Comp > () = GE;}
#line 964 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 18: // RANGE_OPERATOR: G
#line 145 "parser.yy"
                                     {yylhs.value.as < Comp > () = G;}
#line 970 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 19: // RANGE_OPERATOR: LE
#line 145 "parser.yy"
                                                   {yylhs.value.as < Comp > () = LE;}
#line 976 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 20: // RANGE_OPERATOR: L
#line 145 "parser.yy"
                                                                 {yylhs.value.as < Comp > () = L;}
#line 982 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 24: // $@2: %empty
#line 151 "parser.yy"
                                    {if (yystack_[0].value.as < std::string > ().size() > 64) yy::parser::error(yystack_[0].location, "Table name is too large");}
#line 988 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 25: // CREATE_TYPE: CREATE TABLE ID $@2 PI CREATE_LIST PD
#line 151 "parser.yy"
                                                                                                                              {dr.createTable(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::vector<column_t*> > ());}
#line 994 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 26: // SELECT_TYPE: SELECT COLUMNS FROM ID CONDITIONALS
#line 152 "parser.yy"
                                                        {dr.select(yystack_[1].value.as < std::string > (), yystack_[3].value.as < std::vector<std::string>* > (), yystack_[0].value.as < condition_t* > ());}
#line 1000 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 27: // TYPE: INT
#line 155 "parser.yy"
                        {yylhs.value.as < Type > () = Type(Type::Numeric, sizeof(int));}
#line 1006 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 28: // TYPE: DOUBLE
#line 155 "parser.yy"
                                                                         {yylhs.value.as < Type > () = Type(Type::Floating, sizeof(double));}
#line 1012 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 29: // TYPE: CHAR
#line 155 "parser.yy"
                                                                                                                             {yylhs.value.as < Type > () = Type(Type::Char, 1);}
#line 1018 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 30: // TYPE: CHAR PI NUM PD
#line 155 "parser.yy"
                                                                                                                                                                          {yylhs.value.as < Type > () = Type(Type::Char, yystack_[1].value.as < int > ());}
#line 1024 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 31: // TYPE: BOOL
#line 155 "parser.yy"
                                                                                                                                                                                                             {yylhs.value.as < Type > () = Type(Type::Bool, sizeof(bool));}
#line 1030 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 32: // COLUMNS: COLUMNS SEP ID
#line 158 "parser.yy"
                                   {yystack_[2].value.as < std::vector<std::string>* > ()->push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::vector<std::string>* > () = yystack_[2].value.as < std::vector<std::string>* > ();}
#line 1036 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 33: // COLUMNS: ID
#line 158 "parser.yy"
                                                                      {yylhs.value.as < std::vector<std::string>* > () = new std::vector<std::string>{yystack_[0].value.as < std::string > ()};}
#line 1042 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 35: // CONDITIONALS: WHERE CONDITION_LIST
#line 162 "parser.yy"
                                           {yylhs.value.as < condition_t* > () = yystack_[0].value.as < condition_t* > ();}
#line 1048 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 36: // CONDITION_LIST: CONDITION
#line 167 "parser.yy"
                              {yylhs.value.as < condition_t* > () = yystack_[0].value.as < condition_t* > ();}
#line 1054 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 37: // CONDITION: ID EQUAL INPLACE_VALUE
#line 168 "parser.yy"
                                           {yylhs.value.as < condition_t* > () = new condition_t(yystack_[2].value.as < std::string > (), EQUAL, yystack_[0].value.as < Inplace > ());}
#line 1060 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 38: // CONDITION: ID RANGE_OPERATOR INPLACE_VALUE
#line 169 "parser.yy"
                                                      {yylhs.value.as < condition_t* > () = new condition_t(yystack_[2].value.as < std::string > (), yystack_[1].value.as < Comp > (), yystack_[0].value.as < Inplace > ());}
#line 1066 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 42: // CREATE_LIST: CREATE_LIST SEP CREATE_UNIT
#line 176 "parser.yy"
                                                {yylhs.value.as < std::vector<column_t*> > () = yystack_[2].value.as < std::vector<column_t*> > (); yylhs.value.as < std::vector<column_t*> > ().push_back(yystack_[0].value.as < column_t* > ());}
#line 1072 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 43: // CREATE_LIST: CREATE_UNIT
#line 176 "parser.yy"
                                                                                           {yylhs.value.as < std::vector<column_t*> > ().push_back(yystack_[0].value.as < column_t* > ());}
#line 1078 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 44: // CREATE_UNIT: ID TYPE
#line 177 "parser.yy"
                            { yylhs.value.as < column_t* > () = new column_t(yystack_[1].value.as < std::string > (), yystack_[0].value.as < Type > (), 0);}
#line 1084 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;

  case 45: // CREATE_UNIT: ID TYPE PK
#line 178 "parser.yy"
                                 { yylhs.value.as < column_t* > () = new column_t(yystack_[2].value.as < std::string > (), yystack_[1].value.as < Type > (), 1);}
#line 1090 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"
    break;


#line 1094 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

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
      18,    -7,   -26,     1,   -20,   -11,    20,    36,   -40,   -40,
     -40,   -40,   -40,     9,    28,    10,   -40,    -1,    11,   -40,
     -40,    31,    13,     7,    14,    15,   -40,    18,    27,    32,
       4,   -40,    19,   -40,   -40,     7,    29,   -40,     3,    -4,
      13,   -40,   -15,   -40,   -40,   -40,    21,   -40,   -40,   -40,
      48,    33,   -40,   -40,   -40,   -40,     3,   -40,   -40,   -40,
     -40,     3,     8,    -3,   -40,     3,   -40,   -40,   -40,   -40,
     -40,    35,   -40,    34,    21,   -40,   -40,    24,   -40,   -40,
      37,   -40
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,     0,     0,     0,    33,     0,     0,     1,
       3,     0,     0,    34,     0,     0,    24,     2,     0,     0,
      34,    40,     0,    22,    32,    34,     0,     4,     0,     0,
       0,    23,     0,    35,    36,    26,     0,    10,    11,    12,
      16,     0,    13,    14,    41,    39,     0,    17,    18,    19,
      20,     0,     0,     0,    43,     0,    21,    37,    38,    27,
      28,    29,    31,    44,     0,    25,    15,     0,    45,    42,
       0,    30
  };

  const signed char
  parser::yypgoto_[] =
  {
     -40,    38,   -40,   -40,   -39,   -40,    -5,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -25,   -40,   -40,   -40,
      22,   -40,   -13
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     6,    27,     7,    50,    54,    51,    61,     8,     9,
      10,    11,    36,    12,    73,    17,    33,    43,    44,    30,
      31,    63,    64
  };

  const signed char
  parser::yytable_[] =
  {
      53,    74,    56,    24,    13,    41,    14,    18,    40,    25,
      45,    15,    16,    57,    58,    59,    60,    67,    32,    75,
      19,    32,    68,     1,     2,     3,     4,     5,    52,    47,
      48,    49,    69,    70,    71,    72,    47,    48,    49,    20,
      22,    21,    23,    26,    28,    29,    34,    35,    38,    39,
      46,    42,    65,    62,     0,    66,    77,    78,    80,    81,
      76,    79,    55,     0,     0,    37
  };

  const signed char
  parser::yycheck_[] =
  {
      39,     4,    17,     4,    11,    30,    32,    18,     4,    10,
      35,    10,    32,    28,    29,    30,    31,    56,    14,    22,
       0,    14,    61,     5,     6,     7,     8,     9,    32,    33,
      34,    35,    24,    25,    26,    27,    33,    34,    35,     3,
      12,    32,    32,    32,    13,    32,    32,    32,    21,    17,
      21,    32,     4,    32,    -1,    22,    21,    23,    34,    22,
      65,    74,    40,    -1,    -1,    27
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    37,    39,    44,    45,
      46,    47,    49,    11,    32,    10,    32,    51,    18,     0,
       3,    32,    12,    32,     4,    10,    32,    38,    13,    32,
      55,    56,    14,    52,    32,    32,    48,    37,    21,    17,
       4,    52,    32,    53,    54,    52,    21,    33,    34,    35,
      40,    42,    32,    40,    41,    56,    17,    28,    29,    30,
      31,    43,    32,    57,    58,     4,    22,    40,    40,    24,
      25,    26,    27,    50,     4,    22,    42,    21,    23,    58,
      34,    22
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    37,    39,    39,    39,    39,    39,
      40,    40,    40,    41,    41,    42,    42,    43,    43,    43,
      43,    44,    45,    46,    48,    47,    49,    50,    50,    50,
      50,    50,    51,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    58
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     7,     4,     5,     0,     7,     5,     1,     1,     1,
       4,     1,     3,     1,     0,     2,     1,     3,     3,     3,
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
  "VALUES", "WHERE", "AND", "OR", "EQUAL", "TABLE", "INDEX", "COLUMN",
  "PI", "PD", "PK", "INT", "DOUBLE", "CHAR", "BOOL", "GE", "G", "LE", "L",
  "ID", "STRING", "NUM", "FLOATING", "$accept", "PROGRAM", "$@1",
  "SENTENCE", "INPLACE_VALUE", "VALUE", "PARAMS", "RANGE_OPERATOR",
  "INSERT_TYPE", "DELETE_TYPE", "UPDATE_TYPE", "CREATE_TYPE", "$@2",
  "SELECT_TYPE", "TYPE", "COLUMNS", "CONDITIONALS", "CONDITION_LIST",
  "CONDITION", "SET_LIST", "SET_UNIT", "CREATE_LIST", "CREATE_UNIT", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   135,   135,   136,   136,   138,   138,   138,   138,   138,
     140,   141,   142,   143,   143,   144,   144,   145,   145,   145,
     145,   148,   149,   150,   151,   151,   152,   155,   155,   155,
     155,   155,   158,   158,   161,   162,   167,   168,   169,   172,
     172,   173,   176,   176,   177,   178
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
    };
    // Last valid token kind.
    const int code_max = 290;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1503 "/home/juaquin/Documentos/UTEC/Ciclo6/BaseDatos2/projects/Proyecto1/parser/build/parser.tab.cc"

#line 179 "parser.yy"


void yy::parser::error(const location_type &l, const std::string &message){
    std::cerr << "Error: " << message << " at "<<l.end<< "\n";
}
