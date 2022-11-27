/* Simple variant-based parser.   -*- C++ -*-

   Copyright (C) 2018-2021 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

// %require "3.2"
// %language "c++"
%require "3.7"
%language "c++"
%debug 
%defines 
// %define api.namespace {yy}
// %define api.parser.class {parser}


%define api.value.type variant

%code requires
{

#include "scanner12d.h"

}

%parse-param { yyFlexLexer  &scanner }
//%parse-param { Semantics12D &sema  }

%define api.token.constructor

%code
{
  namespace yy
  {
    // Return the next token.
    auto yylex () -> parser::symbol_type
    {
      static int count = 0;
      switch (int stage = count++)
        {
        case 0:
          return parser::make_TEXT ("I have three numbers for you.");
        case 1: case 2: case 3:
          return parser::make_NUMBER (stage);
        case 4:
          return parser::make_TEXT ("And that's all!");
        default:
          return parser::make_YYEOF ();
        }
    }
  }
}
%%

%nterm <std::vector<std::string> *> list;
list:
  %empty        { 
                    /* Generates an empty string list */ 
                    $$ = new std::vector<std::string>();
                }
| list item  { $$ = $1; $$->push_back ($2); }
;

%nterm <std::string> item;
%token <std::string> TEXT;
%token <int> NUMBER;
item:
  TEXT
| NUMBER  { $$ = std::to_string ($1); }
;
%%
namespace yy
{
  // Report an error to the user.
  auto parser::error (const std::string& msg) -> void
  {
    std::cerr << msg << '\n';
  }
}

#if 0
int main ()
{
  yy::parser parse;
  return parse ();
}
#endif
