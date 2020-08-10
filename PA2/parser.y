
%{

#include "lexer.h" 
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg);

%}

%union {
    int integerConstant;
    bool boolConstant;
    char identifier[MaxIdentLen+1]; 





}

%token   T_Void T_Bool T_Int
%token   T_LessEqual T_GreaterEqual T_EQ T_NE T_LeftAngle T_RightAngle
%token   T_And T_Or
%token   T_Equal T_MulAssign T_DivAssign T_AddAssign T_SubAssign
%token   T_While T_For T_If T_Else T_Return T_Break T_Continue
%token   T_Inc T_Dec
%token   T_Semicolon T_Comma
%token   T_Dash T_Plus T_Star T_Slash
%token   T_LeftParen T_RightParen T_LeftBracket T_RightBracket T_LeftBrace T_RightBrace
%token   T_Public T_Private T_Static T_Class

%token   T_Identifier
%token   T_IntConstant
%token   T_BoolConstant

%nonassoc LOWEST
%nonassoc LOWER_THAN_ELSE
%nonassoc T_Else
%right T_Equal T_MulAssign T_DivAssign T_AddAssign T_SubAssign
%left T_Or
%left T_And
%left T_EQ T_NE
%left T_LeftAngle T_RightAngle T_LessEqual T_GreaterEqual
%left T_Plus T_Dash
%left T_Star T_Slash
%left T_Inc T_Dec
%left T_LeftParen T_RightParen


%type <integerConstant>  DeclList
%type <integerConstant>  Decl
%type <integerConstant>  single_declaration 



%%

Program   :    DeclList            {
                                      @1;
                                      if (ReportError::NumErrors() == 0)
                                          printf("Successfully finished parsing\n");
                                    }
          ;

DeclList  :    DeclList Decl        {}
          |    Decl                 
          ;

Decl      :    single_declaration   {}
          |    function_definition  {}
          ;

single_declaration  : type_specifier T_Identifier T_Semicolon                                       {}
                    | type_specifier T_Identifier assignment_operator expression T_Semicolon        {}
                    ;

type_specifier      : T_Void     {}
                    | T_Int      {}
                    | T_Bool     {}
                    ;

function_definition : function_prototype compound_statement_with_scope      {}
                    | function_prototype T_Semicolon                        {}
                    ;

function_prototype  : function_prototype_header T_RightParen    {}
                    ;

function_prototype_header   :   type_specifier T_Identifier T_LeftParen                             {}
                            |   type_specifier T_Identifier T_LeftParen parameter_declaration_list  {}
                            ;

parameter_declaration_list  :   parameter_declaration_list T_Comma  paramater_declaraion    {}
                            |   paramater_declaraion                                        {}
                            ;

paramater_declaraion        :   type_specifier T_Identifier {}
                            ;

compound_statement_with_scope   :   T_LeftBrace statement_list  T_RightBrace    {}
                                |   T_LeftBrace T_RightBrace                    {}
                                ;

statement_list  :   statement_list  statement   {}
                |   statement                   {}
                ;

statement   :   compound_statement_with_scope   {}
            |   simple_statement                {}
            |   iteration_statement             {}
            |   return_statement                {}
            |   decl_statement                  {}
            |   break_statement                 {}
            ;

simple_statement    :   expression_statement    {}
                    |   selection_statement     {}
                    ;

expression_statement    :   T_Semicolon             {}
                        |   expression T_Semicolon  {}
                        ;

selection_statement :   T_If T_LeftParen expression T_RightParen compound_statement_with_scope  {}
                    |   T_If T_LeftParen expression T_RightParen compound_statement_with_scope T_Else compound_statement_with_scope {}
                    ;

iteration_statement :   while_statement {}
                    |   for_statement   {}
                    ;

while_statement :   T_While T_LeftParen condition T_RightParen statement    {}
                ;

for_statement   :   T_For T_LeftParen expression_statement expression_statement expression T_RightParen statement   {}
                ;

condition   :  expression   {}
            ;

return_statement    :   T_Return expression_statement   {}
                    ;

decl_statement  :   single_declaration  {}
                ;

break_statement :   T_Break T_Semicolon {}
                ;

expression  :   assignment_expression   {}
            |   arithmetic_expression   {}
            |   relational_expression   {}
            |   equality_expression     {}
            |   logical_expression      {}
            |   unary_expression        {}
            ;

assignment_expression   :   unary_expression assignment_operator expression {}
                        ;

assignment_operator : T_Equal       {}
                    | T_MulAssign   {}
                    | T_DivAssign   {}
                    | T_AddAssign   {}
                    | T_SubAssign   {}
                    ;

arithmetic_expression   :   expression T_Plus expression    {}
                        |   expression T_Dash expression    {}
                        |   expression T_Star expression    {}
                        |   expression T_Slash expression   {}
                        ;

relational_expression   :   expression T_LeftAngle expression   {}
                        |   expression T_RightAngle expression  {}
                        |   expression T_LessEqual expression   {}
                        |   expression T_GreaterEqual expression{}
                        ;

equality_expression :   expression T_EQ expression  {}
                    |   expression T_NE expression  {}
                    ;

logical_expression  :   expression T_And expression {}
                    |   expression T_Or expression  {}
                    ;

postfix_expression  :   primary_expression          {}
                    |   postfix_expression T_Inc    {}
                    |   postfix_expression T_Dec    {}
                    |   func_call_expression        {}
                    ;

func_call_expression    :   function_call_header_with_parameters T_RightParen   {}
                        |   function_call_header_no_parameters T_RightParen     {}
                        ;

function_call_header_no_parameters  :   function_identfier T_LeftParen T_Void   {}
                                    |   function_identfier T_LeftParen          {}
                                    ;

function_call_header_with_parameters    :   function_identfier T_LeftParen arg_list {}
                                        ;

arg_list    :   assignment_expression                   {}
            |   arg_list T_Comma assignment_expression  {}
            |   primary_expression                      {}
            |   arg_list T_Comma primary_expression     {}
            ;

function_identfier  :   T_Identifier    {}
                    ;

primary_expression  :   T_Identifier    {}
                    |   constant        {}
                    |   T_LeftParen expression T_RightParen {}
                    ;

unary_expression    :   postfix_expression      {}
                    |   T_Inc unary_expression  {}
                    |   T_Dec unary_expression  {}
                    |   T_Plus unary_expression {}
                    |   T_Dash unary_expression {}
                    ;

constant    :   T_IntConstant   {}
            |   T_BoolConstant  {}
            ;

%%

void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
