
#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"

class Decl;
class VarDecl;
class Expr;
class IntConstant;

void yyerror(const char *msg);

class Program : public Node
{
  protected:
     List<Decl*> *decls;

  public:
     Program(List<Decl*> *declList);
     const char *GetPrintNameForNode() { return "Program"; }
     void PrintChildren(int indentLevel);
};

class Stmt : public Node
{
  public:
     Stmt() : Node() {}
     Stmt(yyltype loc) : Node(loc) {}
};

class StmtBlock : public Stmt
{
  protected:
    List<Stmt*> *stmts;

  public:
    StmtBlock(List<Stmt*> *statements);
    const char *GetPrintNameForNode() { return "StmtBlock"; }
    void PrintChildren(int indentLevel);
};


class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;

  public:
    ConditionalStmt() : Stmt(), test(NULL), body(NULL) {}
    ConditionalStmt(Expr *testExpr, Stmt *body);
};

class LoopStmt : public ConditionalStmt
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
};

class ForStmt : public LoopStmt
{
  protected:
    Expr *init, *step;

  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
    const char *GetPrintNameForNode() { return "ForStmt"; }
    void PrintChildren(int indentLevel);
};

class WhileStmt : public LoopStmt
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
    const char *GetPrintNameForNode() { return "WhileStmt"; }
    void PrintChildren(int indentLevel);
};


class IfStmt : public ConditionalStmt
{
  protected:
    Stmt *elseBody;

  public:
    IfStmt() : ConditionalStmt(), elseBody(NULL) {}
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
    const char *GetPrintNameForNode() { return "IfStmt"; }
    void PrintChildren(int indentLevel);
};

class IfStmtExprError : public IfStmt
{
  public:
    IfStmtExprError() : IfStmt() { yyerror(this->GetPrintNameForNode()); }
    const char *GetPrintNameForNode() { return "IfStmtExprError"; }
};

class BreakStmt : public Stmt
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
    const char *GetPrintNameForNode() { return "BreakStmt"; }
};

class ReturnStmt : public Stmt
{
  protected:
    Expr *expr;

  public:
    ReturnStmt(yyltype loc, Expr *expr);
    const char *GetPrintNameForNode() { return "ReturnStmt"; }
    void PrintChildren(int indentLevel);
};

class DeclStmt: public Stmt
{
  protected:
    Decl* varDecl;

  public:
    DeclStmt(yyltype loc, Decl* decl);
    const char *GetPrintNameForNode() { return "DeclStmt"; }
    void PrintChildren(int indentLevel);
};

#endif
