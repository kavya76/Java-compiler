%option yylineno
%{
#include "y.tab.h"
%}
alpha [a-zA-Z]
digit [0-9]
Prnstr (\"(\\.|[^"\\])*\")

%%
[\t|" "|\n]		;{ yylineno = yylineno + 1;}

"import" {yylval.keyname = strdup(yytext);printf("import matched %s",yytext);return IMPORT;}
"static" {yylval.keyname = strdup(yytext);printf("Static matched %s",yytext);return STATIC;}
"public" {yylval.keyname = strdup(yytext);printf("Public matched %s",yytext);return PUBLIC;}
"String" {yylval.keyname = strdup(yytext);printf("String matched %s",yytext);return STRING;}
"class"  {yylval.keyname = strdup(yytext);printf("Class matched %s",yytext);return CLASS;}
"args" {yylval.keyname = strdup(yytext);printf("args matched %s",yytext);return ARGS;}
"main"   {yylval.keyname = strdup(yytext);printf("main matched %s",yytext);return MAIN;}
"System" {yylval.keyname = strdup(yytext);printf("System matched %s",yytext);return SYSTEM;}
"out" 	 {yylval.keyname = strdup(yytext);printf("out matched %s",yytext);return OUT;}
"Void" {yylval.keyname = strdup(yytext);printf("void matched %s",yytext);return VOID;}
"println" {yylval.keyname = strdup(yytext);printf("println matched %s",yytext);return PRINT;}
"int"	{yylval.keyname = strdup(yytext);printf("int matched %s",yytext);return INT;}
"unsigned int"	{yylval.keyname = strdup(yytext);printf("us int matched %s",yytext);return UINT;}
"case"	{yylval.keyname = strdup(yytext);printf("case matched %s",yytext);return CASE;}
"break"	{yylval.keyname = strdup(yytext);printf("break matched %s",yytext);return BREAK;}
"void" {yylval.keyname = strdup(yytext);printf("void matched %s",yytext);return VOID;}
"while"	{yylval.keyname = strdup(yytext);printf("while matched %s",yytext);return WHILE;}
"switch"	{yylval.keyname = strdup(yytext);printf("switch matched %s",yytext);return SWITCH;}
"default" {yylval.keyname = strdup(yytext);printf("default matched %s",yytext);return DEFAULT;}
"if"	{yylval.keyname = strdup(yytext);printf("if matched %s",yytext);return IF;}
"else"	{yylval.keyname = strdup(yytext);printf("else matched %s",yytext);return ELSE;}
{digit}+       {yylval.keyname = strdup(yytext);printf("digit matched %s",yytext);return NUM;}
{alpha}({alpha}|{digit})* {yylval.keyname = strdup(yytext);printf("id matched %s",yytext);return ID;}
"="     {yylval.keyname = strdup(yytext);printf("= matched %s",yytext);return ASGN;}
"<="    {yylval.keyname = strdup(yytext);printf("<= matched %s",yytext);return LE;}
">="    {yylval.keyname = strdup(yytext);printf(">= matched %s",yytext);return GE;}
"=="    {yylval.keyname = strdup(yytext);printf("== matched %s",yytext);return EQ;}
"!="    {yylval.keyname = strdup(yytext);printf("!= matched %s",yytext);return NE;}
">"	{yylval.keyname = strdup(yytext);printf("> matched %s",yytext);return GT;}
"<"	{yylval.keyname = strdup(yytext);printf("< matched %s",yytext);return LT;}
"||" 	{yylval.keyname = strdup(yytext);printf("|| matched %s",yytext);return LOR;}
"&&"  	{yylval.keyname = strdup(yytext);printf("&& matched %s",yytext);return LAND;}
"&"	{yylval.keyname = strdup(yytext);printf("& matched %s",yytext);return BAND;}
"^"	{yylval.keyname = strdup(yytext);printf("^ matched %s",yytext);return BXOR;}
{Prnstr} {yylval.keyname = strdup(yytext);printf("printstmt matched %s",yytext);return PRNSTR;} 
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.	return *yytext;
%%
