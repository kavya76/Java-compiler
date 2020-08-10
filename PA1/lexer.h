#ifndef _H_scanner
#define _H_scanner

#include <stdio.h>

#define MaxIdentLen 31 
typedef enum { 
    T_Void = 256,
    T_Bool, 
    T_Int, 
    T_While, 
    T_Break,
    T_Continue,
    T_Else, 
    T_For, 
    T_If, 
    T_Return, 
    T_Identifier, 
    T_IntConstant, 
    T_BoolConstant, 
    T_Inc,
    T_Dec,
    T_LessEqual,
    T_GreaterEqual,
    T_EQ,
    T_NE,
    T_And, 
    T_Or,
    T_MulAssign,
    T_DivAssign,
    T_AddAssign,
    T_SubAssign,
    T_LeftParen,
    T_RightParen,
    T_LeftBracket,
    T_RightBracket,
    T_LeftBrace,
    T_RightBrace,
    T_Equal,
    T_Semicolon,
    T_Dash,
    T_Plus,
    T_Star,
    T_Slash,
    T_Comma,
    T_LeftAngle,
    T_RightAngle,
    T_Public,
    T_Private,
    T_Static,
    T_Class,
    T_NumTokenTypes
} TokenType;
static const char *gTokenNames[T_NumTokenTypes] = {
  "T_Void", 
  "T_Bool", 
  "T_Int", 
  "T_While", 
  "T_Break", 
  "T_Continue",
  "T_Else", 
  "T_For", 
  "T_If", 
  "T_Return",
  "T_Identifier",
  "T_IntConstant",  
  "T_BoolConstant", 
  "T_Inc",
  "T_Dec",
  "T_LessEqual",
  "T_GreaterEqual",
  "T_EQ",
  "T_NE",
  "T_And", 
  "T_Or", 
  "T_MulAssign",
  "T_DivAssign",
  "T_AddAssign",
  "T_SubAssign",
  "T_LeftParen",
  "T_RightParen",
  "T_LeftBracket",
  "T_RightBracket",
  "T_LeftBrace",
  "T_RightBrace",
  "T_Equal",
  "T_Semicolon",
  "T_Dash",
  "T_Plus",
  "T_Star",
  "T_Slash",
  "T_Comma",
  "T_LeftAngle",
  "T_RightAngle",
  "T_Public",
  "T_Private",
  "T_Static",
  "T_Class"
};

typedef union {
    int integerConstant;
    bool boolConstant;
    char identifier[MaxIdentLen+1]; 
} YYSTYPE;


extern YYSTYPE yylval;

extern char *yytext;      


int yylex();              

#endif
