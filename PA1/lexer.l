%{
#include <iostream>
#include "lexer.h"
#include "location.h"
#include "errors.h"
#include <vector>
using namespace std;

#define TAB_SIZE 8
YYSTYPE yylval;
struct yyltype yylloc;
static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

int currentLineNum, currentColNum;
%}
%x comment

%% 

"\n"                  { currentLineNum++; 
                        currentColNum = 1; }

[ ]+                  {}

"\t"                  { currentColNum = (currentColNum + (TAB_SIZE - (currentColNum%TAB_SIZE)) + 1); }

"//"[^\n]*            {}

"/*"                  { BEGIN(comment); }
<comment>"\n"         { ++currentLineNum; }
<comment>"*"+"/"      { BEGIN(INITIAL); }
<comment>[^\n]*       {}
<comment><<EOF>>      { ReportError::UntermComment(); BEGIN(INITIAL); }

"void"[ \n\t]*        { yylloc.last_column -= 1;
                        return T_Void; }

"boolean"[ \n\t]*     { yylloc.last_column -= 1;
                        return T_Bool; }

"int"[ \n\t]*         { yylloc.last_column -= 1;
                        return T_Int; }

"while"[ \n\t]*       { yylloc.last_column -= 1;
                        return T_While; }

"break"[ \n\t]*      { yylloc.last_column -= 1;
                        return T_Break; }

"continue"[ \n\t]*   { yylloc.last_column -= 1;
                        return T_Continue; }

"else"[ \n\t]*       { yylloc.last_column -= 1;
                        return T_Else; }

"for"[ \n\t]*        { yylloc.last_column -= 1;
                        return T_For; }

"if"[ \n\t]*         { yylloc.last_column -= 1;
                        return T_If; }

"return"[ \n\t]*     { yylloc.last_column -= 1;
                        return T_Return; }

[0-9]+                { yylval.integerConstant = atoi(yytext); 
                        return T_IntConstant; }

"true"|"false"        { yylval.boolConstant = (yytext[0] == 't');
                        return T_BoolConstant; }

"++"                  { return T_Inc; }

"--"                  { return T_Dec; }

"<="                  { return T_LessEqual; }

">="                  { return T_GreaterEqual; }

"=="                  { return T_EQ; }

"!="                  { return T_NE; }

"&&"                  { return T_And; }

"||"                  { return T_Or; }

"*="                  { return T_MulAssign; }

"/="                  { return T_DivAssign; }

"+="                  { return T_AddAssign; }

"-="                  { return T_SubAssign; }

"("                   { return T_LeftParen; }

")"                   { return T_RightParen; }

"["                   { return T_LeftBracket; }

"]"                   { return T_RightBracket; }

"{"                   {  return T_LeftBrace; }

"}"                   { return T_RightBrace; }

"="                   { return T_Equal; }

";"                   { return T_Semicolon; }

"-"                   { return T_Dash; }

"+"                   { return T_Plus; }

"*"                   { return T_Star; }

"/"                   { return T_Slash; }

","                   { return T_Comma; }

"<"                   { return T_LeftAngle; }

">"                   { return T_RightAngle; }

"public"[ \r\n\t]*    { yylloc.last_column -= 1;
                        return T_Public; }

"private"[ \r\n\t]*   { yylloc.last_column -= 1;
                        return T_Private; }

"static"[ \r\n\t]*    { yylloc.last_column -= 1;
                        return T_Static; }

"class"[ \r\n\t]*     { yylloc.last_column -= 1;
                        return T_Class; }

[A-Za-z]+[0-9]*       { size_t len = strlen((char*) yylval.identifier);
                        memset(yylval.identifier, 0, len);
                        strncpy(yylval.identifier, yytext, yyleng);
                        return T_Identifier; }

.                    { ReportError::UnrecogChar(&yylloc, yytext[0]);}






%%
void InitLexer()
{
    currentLineNum = 1;
    currentColNum = 1;
}
static void DoBeforeEachAction()
{
    yylloc.first_line = currentLineNum;
    yylloc.last_line = currentLineNum;

    yylloc.first_column = currentColNum;
    yylloc.last_column = currentColNum + yyleng - 1;
    currentColNum += yyleng;
}

static void PrintOneToken(TokenType token, const char *text, YYSTYPE value,
                          yyltype loc)
{
  char buffer[] = {'\'', (char)token, '\'', '\0'};
  const char *name = token >= T_Void ? gTokenNames[token - T_Void] : buffer;

  printf("%-12s line %d cols %d-%d is %s ", text,
       loc.first_line, loc.first_column, loc.last_column, name);

  switch(token) {
    case T_IntConstant:     
      printf("(value = %d)\n", value.integerConstant); break;
    case T_BoolConstant:    
      printf("(value = %s)\n", value.boolConstant ? "true" : "false"); break;
    case T_Identifier:
  if (strcmp(text, value.identifier)) {
    printf("(truncated to %s)\n", value.identifier);
    break;
  }
    default:
      printf("\n"); break;
  }
}

int main() {
    InitLexer();
    TokenType token;
    while ((token = (TokenType)yylex()) != 0) {
        PrintOneToken(token, yytext, yylval, yylloc);
    }
    return 0;
}
