#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"
#include "symtable.h"

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::PrintChildren(int indentLevel) {
    decls->PrintAll(indentLevel+1);
    printf("\n");
}

StmtBlock::StmtBlock(List<Stmt*> *s) {
    Assert(s != NULL);
    (stmts=s)->SetParentAll(this);
}

void StmtBlock::PrintChildren(int indentLevel) {
    stmts->PrintAll(indentLevel+1);
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && b != NULL);
    (init=i)->SetParent(this);
    step = s;
    if ( s )
      (step=s)->SetParent(this);
}

void ForStmt::PrintChildren(int indentLevel) {
    init->Print(indentLevel+1, "(init) ");
    test->Print(indentLevel+1, "(test) ");
    if ( step )
      step->Print(indentLevel+1, "(step) ");
    body->Print(indentLevel+1, "(body) ");
}

void WhileStmt::PrintChildren(int indentLevel) {
    test->Print(indentLevel+1, "(test) ");
    body->Print(indentLevel+1, "(body) ");
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::PrintChildren(int indentLevel) {
    if (test) test->Print(indentLevel+1, "(test) ");
    if (body) body->Print(indentLevel+1, "(then) ");
    if (elseBody) elseBody->Print(indentLevel+1, "(else) ");
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    expr = e;
    if (e != NULL) expr->SetParent(this);
    symtab->GetScope()->has_return = true;
}

void ReturnStmt::PrintChildren(int indentLevel) {
    if ( expr ) 
      expr->Print(indentLevel+1);
}

DeclStmt::DeclStmt(yyltype loc, Decl *decl) : Stmt(loc) {
    Assert(decl != NULL);
    (varDecl=decl)->SetParent(this);
}

void DeclStmt::PrintChildren(int indentLevel) {
    varDecl->Print(indentLevel+1);
}

void Program::Check() {

    if ( decls->NumElements() > 0 ) {
      for ( int i = 0; i < decls->NumElements(); ++i ) {
        Decl *d = decls->Nth(i);
         d->Check();
      }
    }
}

void StmtBlock::Check(){
    int len = stmts->NumElements();
    Expr * expr;
    for (int i = 0; i < len; i++)
    {
        expr = dynamic_cast<Expr*>(stmts->Nth(i));
        if(expr == NULL)
            stmts->Nth(i)->Check();
        else 
            expr->CheckExpr();
    }
}

void IfStmt::Check(){
    symtab->PushScope();
    Type * expType = test->CheckExpr();
    if(expType != Type::boolType){
        ReportError::TestNotBoolean(test);
    }
    body->Check();
    if(elseBody){
        elseBody->Check();
    }
    symtab->PopScope();
}

void WhileStmt::Check(){
    symtab->PushScope();
    Type * expType = test->CheckExpr();
    Scope * scope = symtab->GetScope();
    scope->is_loop = true;
    if(expType != Type::boolType){
        ReportError::TestNotBoolean(test);
    }
    body->Check();
    symtab->PopScope();
}

void ForStmt::Check(){
    symtab->PushScope();
    Type * expType = test->CheckExpr();
    Scope * scope = symtab->GetScope();
    scope->is_loop = true;
    if(expType != Type::boolType){
        ReportError::TestNotBoolean(test);
    }
    Type * init_type = init->CheckExpr();
    Type * step_type = step->CheckExpr();
    if (init_type != Type::intType || step_type != Type::intType)
    {

    }

    body->Check();
    symtab->PopScope();
}

void ReturnStmt::Check(){
    symtab->GetScope()->has_return = true;
    Type * exprtype = expr->CheckExpr();
    if (exprtype->IsEquivalentTo(Type::bvec4Type))
    {
        exprtype = Type::voidType;
    }
    FnDecl * curr_fn = (FnDecl *) symtab->FindSymbolInAllScopes(symtab->GetScope()->fn_name);
    if (!exprtype->IsEquivalentTo(Type::errorType) && !exprtype->IsEquivalentTo(Type::voidType))
    {

        if(exprtype != curr_fn->GetType())
        {
            ReportError::ReturnMismatch(this, exprtype, curr_fn->GetType());
        }
    }
}

void BreakStmt::Check(){
    Scope * curr_scope = symtab->GetScope();
    if(!curr_scope->is_loop)
    {
        ReportError::BreakOutsideLoop(this);
    }   
}

void DeclStmt::Check(){
    varDecl->Check();
}
