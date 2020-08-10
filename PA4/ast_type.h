
 
#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"
#include <iostream>

using namespace std;

class Type : public Node 
{
  protected:
    char *typeName;

  public :
    static Type *intType, *boolType, *voidType, *errorType, *bvec4Type;

    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);
    
    const char *GetPrintNameForNode() { return "Type"; }
    void PrintChildren(int indentLevel);

    virtual void PrintToStream(ostream& out) { out << typeName; }
    friend ostream& operator<<(ostream& out, Type *t) { t->PrintToStream(out); return out; }
    virtual bool IsEquivalentTo(Type *other) { return (this == other); }
    virtual bool IsConvertibleTo(Type *other) { return (this == other || this == errorType); }
    bool IsNumeric();
    bool IsError();
};


class NamedType : public Type 
{
  protected:
    Identifier *id;
    
  public:
    NamedType(Identifier *i);
    
    const char *GetPrintNameForNode() { return "NamedType"; }
    void PrintChildren(int indentLevel);
    void PrintToStream(ostream& out) { out << id; }
};
 
#endif
