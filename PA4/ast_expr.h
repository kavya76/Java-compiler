

#ifndef _H_ast_expr
#define _H_ast_expr

#include "ast.h"
#include "ast_stmt.h"
#include "list.h"
#include "ast_type.h"


void yyerror(const char *msg);

class Expr : public Stmt 
{
  public:
    Expr(yyltype loc) : Stmt(loc) {}
    Expr() : Stmt() {}

    friend std::ostream& operator<< (std::ostream& stream, Expr * expr) {
        return stream << expr->GetPrintNameForNode();
    }

    virtual Type* CheckExpr() {
      return Type::bvec4Type;
    }

    
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
};

class IntConstant : public Expr 
{
  protected:
    int value;
  
  public:
    IntConstant(yyltype loc, int val);
    const char *GetPrintNameForNode() { return "IntConstant"; }
    void PrintChildren(int indentLevel);
    virtual Type* CheckExpr();
};

class BoolConstant : public Expr 
{
  protected:
    bool value;
    
  public:
    BoolConstant(yyltype loc, bool val);
    const char *GetPrintNameForNode() { return "BoolConstant"; }
    void PrintChildren(int indentLevel);
    virtual Type* CheckExpr();
};

class VarExpr : public Expr
{
  protected:
    Identifier *id;

  public:
    VarExpr(yyltype loc, Identifier *id);
    const char *GetPrintNameForNode() { return "VarExpr"; }
    void PrintChildren(int indentLevel);
    Identifier *GetIdentifier() {return id;}
    virtual Type* CheckExpr();
};

class Operator : public Node 
{
  protected:
    char tokenString[4];
    
  public:
    Operator(yyltype loc, const char *tok);
    const char *GetPrintNameForNode() { return "Operator"; }
    void PrintChildren(int indentLevel);
    friend ostream& operator<<(ostream& out, Operator *o) { return out << o->tokenString; }
    bool IsOp(const char *op) const;
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
    Type* CheckLeftAndRight(Expr* left, Expr* right);
};

class ArithmeticExpr : public CompoundExpr 
{
  public:
    ArithmeticExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    ArithmeticExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    const char *GetPrintNameForNode() { return "ArithmeticExpr"; }
    virtual Type* CheckExpr();
};

class RelationalExpr : public CompoundExpr 
{
  public:
    RelationalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "RelationalExpr"; }
    virtual Type* CheckExpr();
};

class EqualityExpr : public CompoundExpr 
{
  public:
    EqualityExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "EqualityExpr"; }
    virtual Type* CheckExpr();
};

class LogicalExpr : public CompoundExpr 
{
  public:
    LogicalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    LogicalExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    const char *GetPrintNameForNode() { return "LogicalExpr"; }
    virtual Type* CheckExpr();
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
    virtual Type* CheckExpr();
};

class PostfixExpr : public CompoundExpr
{
  public:
    PostfixExpr(Expr *lhs, Operator *op) : CompoundExpr(lhs,op) {}
    const char *GetPrintNameForNode() { return "PostfixExpr"; }
    virtual Type* CheckExpr();
};

class ConditionalExpr : public Expr
{
  protected:
    Expr *cond, *trueExpr, *falseExpr;
  public:
    ConditionalExpr(Expr *c, Expr *t, Expr *f);
    void PrintChildren(int indentLevel);
    const char *GetPrintNameForNode() { return "ConditionalExpr"; }
};

class LValue : public Expr 
{
  public:
    LValue(yyltype loc) : Expr(loc) {}
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
    virtual Type* CheckExpr();
};

class ActualsError : public Call
{
  public:
    ActualsError() : Call() { yyerror(this->GetPrintNameForNode()); }
    const char *GetPrintNameForNode() { return "ActualsError"; }
};

#endif
