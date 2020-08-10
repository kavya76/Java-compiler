
#ifndef _H_ast
#define _H_ast
#include <stdlib.h>  
#include "location.h"
#include <iostream>

using namespace std;

class SymbolTable;

class Node  {
  protected:
    yyltype *location;
    Node *parent;
    static SymbolTable *symtab;

  public:
    Node(yyltype loc);
    Node();
    virtual ~Node() {}
    
    yyltype *GetLocation()   { return location; }
    void SetParent(Node *p)  { parent = p; }
    Node *GetParent()        { return parent; }

    virtual const char *GetPrintNameForNode() = 0;
    
    void Print(int indentLevel, const char *label = NULL); 
    virtual void PrintChildren(int indentLevel)  {}

    virtual void Check() {}
};
   

class Identifier : public Node 
{
  protected:
    char *name;
    
  public:
    Identifier(yyltype loc, const char *name);
    const char *GetPrintNameForNode()   { return "Identifier"; }
    char *GetName() const { return name; }
    void PrintChildren(int indentLevel);
    friend ostream& operator<<(ostream& out, Identifier *id) { return out << id->name; }
};


class Error : public Node
{
  public:
    Error() : Node() {}
    const char *GetPrintNameForNode()   { return "Error"; }
};



#endif
