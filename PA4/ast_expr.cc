#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "symtable.h"
#include "errors.h"

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}
void IntConstant::PrintChildren(int indentLevel) { 
    printf("%d", value);
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}
void BoolConstant::PrintChildren(int indentLevel) { 
    printf("%s", value ? "true" : "false");
}

VarExpr::VarExpr(yyltype loc, Identifier *ident) : Expr(loc) {
    Assert(ident != NULL);
    this->id = ident;
}

void VarExpr::PrintChildren(int indentLevel) {
    id->Print(indentLevel+1);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

void Operator::PrintChildren(int indentLevel) {
    printf("%s",tokenString);
}

bool Operator::IsOp(const char *op) const {
    return strcmp(tokenString, op) == 0;
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o) 
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(l != NULL && o != NULL);
    (left=l)->SetParent(this);
    (op=o)->SetParent(this);
}

void CompoundExpr::PrintChildren(int indentLevel) {
   if (left) left->Print(indentLevel+1);
   op->Print(indentLevel+1);
   if (right) right->Print(indentLevel+1);
}

SelectionExpr::SelectionExpr(Expr *c, Expr *t, Expr *f)
  : Expr(Join(c->GetLocation(), f->GetLocation())) {
    Assert(c != NULL && t != NULL && f != NULL);
    (cond=c)->SetParent(this);
    (trueExpr=t)->SetParent(this);
    (falseExpr=f)->SetParent(this);
}

void SelectionExpr::PrintChildren(int indentLevel) {
    cond->Print(indentLevel+1);
    trueExpr->Print(indentLevel+1, "(true) ");
    falseExpr->Print(indentLevel+1, "(false) ");
}
   
ConditionalExpr::ConditionalExpr(Expr *c, Expr *t, Expr *f)
  : Expr(Join(c->GetLocation(), f->GetLocation())) {
    Assert(c != NULL && t != NULL && f != NULL);
    (cond=c)->SetParent(this);
    (trueExpr=t)->SetParent(this);
    (falseExpr=f)->SetParent(this);
}

void ConditionalExpr::PrintChildren(int indentLevel) {
    cond->Print(indentLevel+1, "(cond) ");
    trueExpr->Print(indentLevel+1, "(true) ");
    falseExpr->Print(indentLevel+1, "(false) ");
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::PrintChildren(int indentLevel) {
   if (base) base->Print(indentLevel+1);
   if (field) field->Print(indentLevel+1);
   if (actuals) actuals->PrintAll(indentLevel+1, "(actuals) ");
}

Type* IntConstant::CheckExpr() {
    return Type::intType;
}

Type* BoolConstant::CheckExpr() {
    return Type::boolType;
}

Type* VarExpr::CheckExpr() {
    VarDecl * dec;
    if(symtab->IsInAllScopes(id->GetName())){
        dec = (VarDecl *) symtab->FindSymbolInAllScopes(id->GetName());
        return dec->GetType();
    }
    ReportError::IdentifierNotDeclared(id, LookingForVariable);
    return Type::errorType;
}

Type* Call::CheckExpr() {
    bool temp = symtab->IsInAllScopes(field->GetName());
    if (!temp)
    {
        ReportError::IdentifierNotDeclared(field, LookingForFunction);
        return Type::errorType;
    }
    else
    {
        FnDecl * fn_decl = (FnDecl *) symtab->FindSymbolInAllScopes(field->GetName());
        int actual_size = fn_decl->GetFormals()->NumElements();
        int arg_size = actuals->NumElements();
        if (arg_size < actual_size)
        {
            ReportError::LessFormals(field, actual_size, arg_size);
            return Type::errorType;
        }
        else if (arg_size > actual_size)
        {
            ReportError::ExtraFormals(field, actual_size, arg_size);
            return Type::errorType;
        }
        else
        {
            Type * expected;
            VarDecl * arg;
            for (int i = 0; i < actual_size; i++)
            {
                arg = fn_decl->GetFormals()->Nth(i);
                arg->Check();
                expected = actuals->Nth(i)->CheckExpr();
                if (arg->GetType() != expected)
                {
                    ReportError::FormalsTypeMismatch(field, i, arg->GetType(), expected );
                }
            }
            return fn_decl->GetType();
        }
    }
}

Type* ArithmeticExpr::CheckExpr() {
    if (left)
    {
        Type * ltemp = left->CheckExpr();
        Type * rtemp = right->CheckExpr();    
        if(ltemp->IsEquivalentTo(Type::errorType) || rtemp->IsEquivalentTo(Type::errorType))
        {
            return Type::errorType;
        }
        else if (ltemp->IsEquivalentTo(Type::boolType) || rtemp->IsEquivalentTo(Type::boolType))
        {
            ReportError::IncompatibleOperands(op, ltemp, rtemp);
            return Type::errorType;
        }
        else
        {
            return Type::intType;
        }
    }
    else
    {
        Type * rtemp = right->CheckExpr();
        if (rtemp->IsEquivalentTo(Type::errorType))
        {
            return rtemp;
        }
        else if (rtemp->IsEquivalentTo(Type::boolType))
        {
            ReportError::IncompatibleOperand(op, rtemp);
            return Type::errorType;
        }
        else{
            return Type::intType;
        }
    }
}

Type* RelationalExpr::CheckExpr() {
    Type * ltemp = left->CheckExpr();
    Type * rtemp = right->CheckExpr(); 
       
    if(ltemp->IsEquivalentTo(Type::intType) && rtemp->IsEquivalentTo(Type::intType))
    {
        return Type::boolType;
    }
    return Type::errorType;
       
}

Type* EqualityExpr::CheckExpr() {
    Type * ltemp = left->CheckExpr();
    Type * rtemp = right->CheckExpr();    
    if(ltemp->IsEquivalentTo(Type::boolType) && rtemp->IsEquivalentTo(Type::boolType))
    {
        return Type::boolType;
    }
    else if(ltemp->IsEquivalentTo(Type::intType) && rtemp->IsEquivalentTo(Type::intType))
    {
        return Type::boolType;
    }
    else
    {
        ReportError::IncompatibleOperands(op, ltemp, rtemp);
        return Type::errorType;
    }
}

Type* LogicalExpr::CheckExpr() {
    Type * ltemp = left->CheckExpr();
    Type * rtemp = right->CheckExpr();    
    if(ltemp->IsEquivalentTo(Type::boolType) && rtemp->IsEquivalentTo(Type::boolType))
    {
        return Type::boolType;
    }
    return Type::errorType;
}

Type* AssignExpr::CheckExpr() {
    Type * rtemp = right->CheckExpr();
    Type * ltemp = left->CheckExpr();
    if (rtemp->IsEquivalentTo(Type::errorType) || ltemp->IsEquivalentTo(Type::errorType))
    {
        return Type::errorType;
    }
    if (ltemp != rtemp)
    {
        ReportError::IncompatibleOperands(op, ltemp, rtemp);
    }
    return ltemp;
}

Type* PostfixExpr::CheckExpr() {
    Type * vartype = left->CheckExpr();
    if(vartype == Type::boolType){
        ReportError::IncompatibleOperand(op, vartype);
        return Type::errorType;
    }
    else{
        return Type::intType;
    }
}
