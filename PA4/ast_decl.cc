#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "symtable.h"     
#include "errors.h"   
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

VarDecl::VarDecl(Identifier *n, Type *t, Expr *e) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
    if (e) (assignTo=e)->SetParent(this);
}
  
void VarDecl::PrintChildren(int indentLevel) { 
   if (type) type->Print(indentLevel+1);
   if (id) id->Print(indentLevel+1);
   if (assignTo) assignTo->Print(indentLevel+1, "(initializer) ");
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r != NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::PrintChildren(int indentLevel) {
    if (returnType) returnType->Print(indentLevel+1, "(return type) ");
    if (id) id->Print(indentLevel+1);
    if (formals) formals->PrintAll(indentLevel+1, "(formals) ");
    if (body) body->Print(indentLevel+1, "(body) ");
}

void VarDecl::Check() {
    
    if( symtab->IsInCurrentScope( id->GetName() ) ){
        Decl* previous_decl = symtab->FindSymbolInCurrentScope( id->GetName() );
        ReportError::DeclConflict(this, previous_decl);
    }
    

    if(assignTo) {
        Type* rhs_type = assignTo->CheckExpr();
        if (rhs_type != Type::errorType && rhs_type != this->GetType())
        {
            ReportError::InvalidInitialization(id, this->GetType(), rhs_type);
        }
    }

    symtab->AddSymbol(id->GetName(),this);
}

void FnDecl::Check() {
    if( symtab->IsInCurrentScope( id->GetName() ) ){
        Decl* previous_decl = symtab->FindSymbolInCurrentScope( id->GetName() );
        ReportError::DeclConflict(this, previous_decl);
        return;
    }    

    symtab->AddSymbol(id->GetName(),this);

    symtab->PushScope();
    Scope * current_scope = symtab->GetScope();
    current_scope->fn_name = id->GetName();

    for(int i = 0; i < formals->NumElements(); i++){
        formals->Nth(i)->Check();
    }

    body->Check();
    

    Type * curr_fn_type = this->GetType();
    if (!current_scope->has_return && curr_fn_type != Type::voidType)
    {
        ReportError::ReturnMissing(this);
    }

    symtab->PopScope();
}
