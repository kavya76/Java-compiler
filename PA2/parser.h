

#ifndef _H_parser
#define _H_parser

 
  
#include "lexer.h"            
#include "utility.h"
 


#ifndef YYBISON                 
#include "y.tab.h"              
#endif

int yyparse();              
void InitParser();        

#endif
