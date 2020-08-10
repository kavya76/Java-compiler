#ifndef _H_ast_expr
#define _H_ast_expr

#include "ast.h"
#include "ast_stmt.h"
#include "list.h"
#include <string>
using namespace std;

class NamedType;
class Type; 

void yyerror(const char *msg);

class Expr : public Stmt
{
  public:
    Expr(yyltype loc) : Stmt(loc) {}
    Expr() : Stmt() {}
};

class ExprError : public Expr
{
  public:
    ExprError() : Expr() { yyerror(this->GetPrintNameForNode()); }
    const char *GetPrintNameForNode() { return "ExprError"; }
};


class EmptyExpr : public Expr
{
  public:
    const char *GetPrintNameForNode() { return "Empty"; }
    virtual string Emit();
};

class IntConstant : public Expr
{
  protected:
    int value;

  public:
    IntConstant(yyltype loc, int val);
    const char *GetPrintNameForNode() { return "IntConstant"; }
    void PrintChildren(int indentLevel);
    int GetValue() { return value; }
    virtual string Emit();
};

class BoolConstant : public Expr
{
  protected:
    bool value;

  public:
    BoolConstant(yyltype loc, bool val);
    const char *GetPrintNameForNode() { return "BoolConstant"; }
    void PrintChildren(int indentLevel);
    bool GetValue() { return value; }
    virtual string Emit();
};

class Operator : public Node
{
  protected:
    char tokenString[4];

  public:
    Operator(yyltype loc, const char *tok);
    const char *GetPrintNameForNode() { return "Operator"; }
    void PrintChildren(int indentLevel);
    virtual string Emit();
 };

class CompoundExpr : public Expr
{
  protected:
    Operator *op;
    Expr *left, *right;

  public:
    CompoundExpr(Expr *lhs, Operator *op, Expr *rhs); 
    CompoundExpr(Operator *op, Expr *rhs);             
    CompoundExpr(Expr *lhs, Operator *op);             
    void PrintChildren(int indentLevel);
};

class ArithmeticExpr : public CompoundExpr
{
  public:
    ArithmeticExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    ArithmeticExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    const char *GetPrintNameForNode() { return "ArithmeticExpr"; }
    virtual string Emit();
};

class RelationalExpr : public CompoundExpr
{
  public:
    RelationalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "RelationalExpr"; }
    virtual string Emit();
};

class EqualityExpr : public CompoundExpr
{
  public:
    EqualityExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "EqualityExpr"; }
    virtual string Emit();
};

class LogicalExpr : public CompoundExpr
{
  public:
    LogicalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    LogicalExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    const char *GetPrintNameForNode() { return "LogicalExpr"; }
    virtual string Emit();
};

class SelectionExpr : public Expr
{
  protected:
    Expr *cond, *trueExpr, *falseExpr;
  public:
    SelectionExpr(Expr *c, Expr *t, Expr *f);
    void PrintChildren(int indentLevel);
    const char *GetPrintNameForNode() { return "SelectionExpr"; }
};

class AssignExpr : public CompoundExpr
{
  public:
    AssignExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "AssignExpr"; }
    virtual string Emit();
};

class PostfixExpr : public CompoundExpr
{
  public:
    PostfixExpr(Expr *lhs, Operator *op) : CompoundExpr(lhs,op) {}
    const char *GetPrintNameForNode() { return "PostfixExpr"; }
    virtual string Emit();
};


class Call : public Expr
{
  protected:
    Expr *base;
    Identifier *field;
    List<Expr*> *actuals;

  public:
    Call() : Expr(), base(NULL), field(NULL), actuals(NULL) {}
    Call(yyltype loc, Expr *base, Identifier *field, List<Expr*> *args);
    const char *GetPrintNameForNode() { return "Call"; }
    void PrintChildren(int indentLevel);
    virtual string Emit();
};

class VarExpr : public Expr
{
  protected:
    Identifier *id;
  public:
    VarExpr(yyltype loc, Identifier *ident);
    const char *GetPrintNameForNode() { return "VarExpr"; }
    void PrintChildren(int identLevel);
    string GetName() {return id->GetName();}
    virtual string Emit();
};

#endif
