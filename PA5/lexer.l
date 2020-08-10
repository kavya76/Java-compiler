%{
#include <iostream>
#include "lexer.h"
#include "location.h"
#include "errors.h"
#include <vector>
#include "utility.h"
#include "parser.h"
using namespace std;

#define TAB_SIZE 8

vector<const char*> savedLines;

static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

int currentLineNum, currentColNum;
%}
%x comment
%x COPY
%option stack

%% 
<COPY>.*              { savedLines.push_back(strdup(yytext));
                        currentColNum = 1;
                        yy_pop_state(); 
                        yyless(0);}

<COPY><<EOF>>         { yy_pop_state(); }

<*>\n                 { currentLineNum++; currentColNum = 1;
                        if (YYSTATE == COPY) savedLines.push_back("");
                        else yy_push_state(COPY);}

[ ]+                  {}

"\t"                  { currentColNum = (currentColNum + (TAB_SIZE - (currentColNum%TAB_SIZE)) + 1); }

"//"[^\n]*            {}

"/*"                  { BEGIN(comment); }
<comment>"*"+"/"      { BEGIN(INITIAL); }
<comment><<EOF>>      { ReportError::UntermComment(); BEGIN(INITIAL); }
<comment>.            { }

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
    yy_flex_debug = false;
    currentLineNum = 1;
    currentColNum = 1;
    yy_push_state(COPY);
}

static void DoBeforeEachAction()
{
    yylloc.first_line = currentLineNum;
    yylloc.last_line = currentLineNum;

    yylloc.first_column = currentColNum;
    yylloc.last_column = currentColNum + yyleng - 1;
    currentColNum += yyleng;
}

 const char* GetLineNumbered(int num) {
     if (num <= 0 || num > savedLines.size()) return NULL;
     return savedLines[num-1];
 }
 
