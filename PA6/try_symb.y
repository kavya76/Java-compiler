%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int yylex();
extern FILE *fp;
FILE * f1;
char temp[20];

char keywords[300][500];

int keycount=0;
typedef struct ident{
	
	char type[7];
	char idname[15];
	int line;

} token;

token identifier[20];

int identcount=0;

void insertidenttoken(char *a, char *b, int c){
	strcpy(identifier[identcount].type,a);

	strcpy(identifier[identcount].idname,b);
	identifier[identcount].line=c;	
	identcount++;

}

void displayidenttokens(){
	int i=0;
	for(i=0; i<identcount; i++){
		printf("Identifier, %s, %s, lineno: %d \n", identifier[i].type, identifier[i].idname, identifier[i].line);

	}

}
void keywordstable(char *a){
	
	//printf("\ncomes here : ");
	//printf("%s\n",a);
	strcpy(keywords[keycount++],a);

}

void displaykeywordtokens(){
	printf("******************************Symbol Table***********************************\n");
	int i=0;
    for(i=0;i<keycount;i++){
    	printf("< keyword, %s >\n",keywords[i]);
    }
}
%}

%union{
	
	char *keyname;
	char *typename;
	char *idname;
	char *intval;
	char  *flotval;
}

%error-verbose

%token STRING IMPORT STATIC PUBLIC CLASS ARGS MAIN
%token SYSTEM OUT VOID PRINT UINT INT
%token WHILE PRNSTR 
%token IF ELSE SWITCH CASE BREAK DEFAULT
%token NUM ID
%token INCLUDE
%type <keyname> VOID MAIN IF ELSE WHILE PUBLIC CLASS ARGS STATIC SYSTEM OUT PRINT STRING IMPORT FOR
%type <keyname> SWITCH CASE BREAK DEFAULT 
%type <typename> INT UINT  
%type <intval> NUM
%type <idname> ID
%right ASGN 
%left LOR
%left LAND
%left BOR
%left BXOR
%left BAND
%left EQ NE 
%left LE GE LT GT
%left '+' '-' 
%left '*' '/' '@'
%left '~'

%nonassoc IFX IFX1
%nonassoc ELSE
  
%%

Start : IMPORT ID ';' Start        {keywordstable($1);keywordstable($2);}    
	 |Here
	 ;

Here : PUBLIC CLASS ID '{' pgmstart '}'     {keywordstable($1);keywordstable($2);}  
     ;

pgmstart : PUBLIC STATIC VOID MAIN '('  STRING ARGS ')' STMTS {keywordstable($1);keywordstable($2);keywordstable($3);keywordstable($4);}
	;

STMTS 	: '{' STMT1 '}'|
				;
STMT1			: STMT  STMT1
				| 
				;

STMT 			: STMT_DECLARE    //all types of statements
				| STMT_ASSGN  
				| STMT_IF
				| STMT_WHILE
				| STMT_SWITCH
				| print_stmt
				| ';'
				;

				

EXP 			: EXP LT{push();} EXP {codegen_logical();}
				| EXP LE{push();} EXP {codegen_logical();}
				| EXP GT{push();} EXP {codegen_logical();}
				| EXP GE{push();} EXP {codegen_logical();}
				| EXP NE{push();} EXP {codegen_logical();}
				| EXP EQ{push();} EXP {codegen_logical();}
				| EXP '+'{push();} EXP {codegen_algebric();}
				| EXP '-'{push();} EXP {codegen_algebric();}
				| EXP '*'{push();} EXP {codegen_algebric();}
				| EXP '/'{push();} EXP {codegen_algebric();}
				| EXP {push();} LOR EXP {codegen_logical();}
				| EXP {push();} LAND EXP {codegen_logical();}
				| EXP {push();} BOR EXP {codegen_logical();}
				| EXP {push();} BXOR EXP {codegen_logical();}
				| EXP {push();} BAND EXP {codegen_logical();}
				| '(' EXP ')'
				| ID {check();push();}
				| NUM {push();}
				;

print_stmt : 	SYSTEM '.' OUT '.' PRINT '('PRNSTR')' ';'    {keywordstable($1);keywordstable($3);keywordstable($5);}     
				;

STMT_IF 			: IF '(' EXP ')'  {if_label1();} STMTS ELSESTMT {keywordstable($1);}
				;
ELSESTMT		: ELSE {if_label2();} STMTS {if_label3();} {keywordstable($1);}
				| {if_label3();}
				;

STMT_SWITCH		: SWITCH '(' EXP ')' {switch_start();} '{' SWITCHBODY '}' {keywordstable($1);}
				;
SWITCHBODY		: CASES {switch_end();}    
				| CASES DEFAULTSTMT {switch_end();}
				;

CASES 			: CASE NUM {switch_case();} ':' SWITCHEXP BREAKSTMT {keywordstable($1);}
				| 
				;
BREAKSTMT		: BREAK {switch_break();} ';' CASES {keywordstable($1);}
				|{switch_nobreak();} CASES 
				;

DEFAULTSTMT 	: DEFAULT {switch_default();} ':' SWITCHEXP DE  {keywordstable($1);}
				;

DE 				: BREAK {switch_break();}';' {keywordstable($1);}
				|
				;


SWITCHEXP 		: STMTS
				| STMT
				;


STMT_WHILE		:{while_start();} WHILE '(' EXP ')' {while_rep();} WHILEBODY  {keywordstable($2);}
				;

WHILEBODY		: STMTS {while_end();}
				| STMT {while_end();}
				;


STMT_DECLARE 	: TYPE {setType();}  ID {STMT_DECLARE();} IDS   //setting type for that line
				;


IDS 			: ';'
				| ','  ID {STMT_DECLARE();} IDS 
				;


STMT_ASSGN		: ID {push();} ASGN {push();} EXP {codegen_assign();} ';'
				;


TYPE			: INT {keywordstable($1);}
				| VOID {keywordstable($1);}
				| UINT {keywordstable($1);}
				;

%%

#include <ctype.h>
#include"lex.yy.c"
int count=0;

char st[1000][10];
int top=0;
int i=0;
char tmp[2]="t";

int label[200];
int lnum=0;
int ltop=0;
int switch_stack[1000];
int stop=0;
char type[10];
struct Table
{
	char id[20];
	char type[10];
}table[10000];
int tableCount=0;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1],"r");
	f1=fopen("output","w");
	
   if(!yyparse())
		printf("\n\n\nParsing Successfull\n\n");
	else
	{
		printf("\nParsing failed\n");
		exit(0);
	}
	
	fclose(yyin);
	fclose(f1);
	displaykeywordtokens();
    	displayidenttokens();
	intermediateCode();
    return 0;
}
         
int yyerror(const char *msg)
{
	printf("\n\n\n\n\nParsing Failed\nLine Number: %d  : %s\n",yylineno,msg);
//	success = 0;
	return 0;

}
    
push()
{
  	strcpy(st[++top],yytext);
}

codegen_logical()
{
 	sprintf(tmp,"$t%d",i);
  	fprintf(f1,"%s\t=\t%s\t%s\t%s\n",tmp,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],tmp);
 	i++;
}

codegen_algebric()
{
 	sprintf(tmp,"$t%d",i); // converts tmp to reqd format
  	fprintf(f1,"%s\t=\t%s\t%s\t%s\n",tmp,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],tmp);
 	i++;
}
codegen_assign()
{
 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
 	top-=3;
}
 
if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}

if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\t\tgoto $L%d\n",lnum);
	fprintf(f1,"$L%d: \n",x); 
	label[++ltop]=lnum;
}

if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"$L%d: \n",y);
	top--;
}
while_start()
{
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"$L%d:\n",lnum);
}

while_rep()
{
	lnum++;
 	fprintf(f1,"if( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}
while_end()
{
	int x,y;
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\t\tgoto $L%d\n",x);
	fprintf(f1,"$L%d: \n",y);
	top--;
}
switch_start()
{
	lnum++;
	label[++ltop]=lnum;
	lnum++;
	label[++ltop]=lnum;
	switch_stack[++stop]=1;
}
switch_case()
{
	int x,y,z;
	z=switch_stack[stop--];
	if(z==1)
	{
		x=label[ltop--];
	}
	else if(z==2)
	{
		y=label[ltop--];
		x=label[ltop--];
	}
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
 	fprintf(f1,"if(%s != %s)",st[top],yytext);
 	fprintf(f1,"\tgoto $L%d\n",label[ltop]);
 	if(z==2)
 	{
 		fprintf(f1,"$L%d:\n",y);
 	}
}
switch_default()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
}
switch_break()
{
	switch_stack[++stop]=1;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop-1]);
}
switch_nobreak()
{
	switch_stack[++stop]=2;
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop]);
}
switch_end()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	top--;
	stop--;
}


/* for symbol table*/

check()
{
	char tmp[20];
	strcpy(tmp,yytext);
	int flag=0;
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,tmp))
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		yyerror("Variable not declard");
		exit(0);
	}
}

setType()
{
	strcpy(type,yytext);
}


STMT_DECLARE()
{
	char tmp[20];
	int i,flag;
	flag=0;
	strcpy(tmp,yytext);
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,tmp))
			{
			flag=1;
			break;
				}
	}
	if(flag)
	{
		yyerror("reSTMT_DECLARE of ");
		exit(0);
	}
	else
	{
		strcpy(table[tableCount].id,tmp);
		strcpy(table[tableCount].type,type);
		tableCount++;
	}
}

intermediateCode()
{
	int Labels[100000];
	char buf[100];
	f1=fopen("output","r");
	int flag=0,lineno=1;
	memset(Labels,0,sizeof(Labels));
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		//printf("%s",buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			int k=atoi(&buf[3]);
			//printf("hi %d\n",k);
			Labels[k]=lineno;
		}
		else
		{
			lineno++;
		}
	}
	fclose(f1);
	f1=fopen("output","r");
	lineno=0;

	printf("\n\n\n*********************InterMediate Code***************************\n\n");
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			;
		}
		else
		{
			flag=0;
			lineno++;
			printf("%3d:\t",lineno);
			int len=strlen(buf),i,flag1=0;
			for(i=len-3;i>=0;i--)
			{
				if(buf[i]=='$'&&buf[i+1]=='$'&&buf[i+2]=='L')
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			{
				buf[i]=='\0';
				int k=atoi(&buf[i+3]),j;
				//printf("%s",buf);
				for(j=0;j<i;j++)
					printf("%c",buf[j]);
				printf(" %d\n",Labels[k]);
			}
			else printf("%s",buf);
		}
	}
	printf("%3d:\tend\n",++lineno);
	fclose(f1);
}
