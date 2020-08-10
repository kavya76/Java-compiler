
#ifndef _H_parser
#define _H_parser

  
#include "lexer.h"            
#include "list.h"       	
#include "ast.h"		
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "ast_stmt.h"
#ifndef YYBISON                 
#include "y.tab.h"              
#endif

int yyparse();             
void InitParser();         

#endif
