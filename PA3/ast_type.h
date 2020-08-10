
#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"

class Type : public Node
{
  protected:
    char *typeName;

  public :
    static Type *intType, *boolType, *voidType, *errorType;

    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);

    const char *GetPrintNameForNode() { return "Type"; }
    void PrintChildren(int indentLevel);
};

class NamedType : public Type
{
  protected:
    Identifier *id;

  public:
    NamedType(Identifier *i);

    const char *GetPrintNameForNode() { return "NamedType"; }
    void PrintChildren(int indentLevel);
};

#endif
