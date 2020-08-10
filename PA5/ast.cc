#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "symtable.h"
#include <string.h>
#include <stdio.h> 
#include <string>
#include <vector>
using namespace std;

Node::Node(yyltype loc) {
    location = new yyltype(loc);
    parent = NULL;
}

Node::Node() {
    location = NULL;
    parent = NULL;
}

SymbolTable *Node::symtab = new SymbolTable();

int Node::registerCounter = 1;
int Node::labelCounter = 0;
int Node::varCounter = 0;
int Node::mipsReg = 0;
set<string> Node::localVars = {};
vector<TACObject> Node::TACContainer = {};
map<string, bool> Node::globalVars = {};
bool Node::inFunc = false;
map<string, int> Node::propMap = {};
map<string, bool> Node::deadMap = {};
map<string, string> Node::mipsMap = {};

void Node::Print(int indentLevel, const char *label) { 
    const int numSpaces = 3;
    printf("\n");
    if (GetLocation()) 
        printf("%*d", numSpaces, GetLocation()->first_line);
    else 
        printf("%*s", numSpaces, "");
    printf("%*s%s%s: ", indentLevel*numSpaces, "", 
           label? label : "", GetPrintNameForNode());
   PrintChildren(indentLevel);
} 
	 
string Node::Emit() {
    cout << "In Node class's Emit()" << endl;
    return NULL;
}     
Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
} 

void Identifier::PrintChildren(int indentLevel) {
    printf("%s", name);
}
