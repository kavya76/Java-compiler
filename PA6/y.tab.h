/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    IMPORT = 259,
    STATIC = 260,
    PUBLIC = 261,
    CLASS = 262,
    ARGS = 263,
    MAIN = 264,
    SYSTEM = 265,
    OUT = 266,
    VOID = 267,
    PRINT = 268,
    UINT = 269,
    INT = 270,
    WHILE = 271,
    PRNSTR = 272,
    IF = 273,
    ELSE = 274,
    SWITCH = 275,
    CASE = 276,
    BREAK = 277,
    DEFAULT = 278,
    NUM = 279,
    ID = 280,
    INCLUDE = 281,
    ASGN = 282,
    LOR = 283,
    LAND = 284,
    BOR = 285,
    BXOR = 286,
    BAND = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    LT = 292,
    GT = 293,
    IFX = 294,
    IFX1 = 295
  };
#endif
/* Tokens.  */
#define STRING 258
#define IMPORT 259
#define STATIC 260
#define PUBLIC 261
#define CLASS 262
#define ARGS 263
#define MAIN 264
#define SYSTEM 265
#define OUT 266
#define VOID 267
#define PRINT 268
#define UINT 269
#define INT 270
#define WHILE 271
#define PRNSTR 272
#define IF 273
#define ELSE 274
#define SWITCH 275
#define CASE 276
#define BREAK 277
#define DEFAULT 278
#define NUM 279
#define ID 280
#define INCLUDE 281
#define ASGN 282
#define LOR 283
#define LAND 284
#define BOR 285
#define BXOR 286
#define BAND 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define LT 292
#define GT 293
#define IFX 294
#define IFX1 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "try_symb.y" /* yacc.c:1909  */

	
	char *keyname;
	char *typename;
	char *idname;
	char *intval;
	char  *flotval;

#line 143 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
