#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "symtable.h"

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

string VarDecl::Emit() {
    string varName = GetIdentifier()->GetName();
    if (!inFunc)
    {
        globalVars[varName] = true;
    }
    if (assignTo) {
        string rhsRegisterName = assignTo->Emit();
        TACObject a;
        a.type = 14;
        a.l17 = varName;
        a.l18 = rhsRegisterName;
        a.complete();
        TACContainer.push_back(a);
    }     

    return "VarDecl::Emit()";
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) {
    (body=b)->SetParent(this);
}

string FnDecl::Emit() {
    inFunc = true;
    
    TACObject b;
    b.type = 1;
    b.l0 = string(id->GetName());
    b.complete();
    TACContainer.push_back(b);

    
    int paramLength = formals->NumElements();
    for (int i = 0; i < paramLength; i++)
    {
        TACObject a;
        a.type = 2;
        a.acname= "LoadParam ";
        a.acitem = formals->Nth(i)->GetIdentifier()->GetName();
        a.complete();
        TACContainer.push_back(a);

    }
    int index = TACContainer.size();
    int diff = registerCounter;
    int vars = 0;
    localVars.clear();

    body->Emit();
    diff = registerCounter - diff;
    vars = localVars.size();
    int numBytes = (paramLength + diff + vars) * sizeof(int);
    
    TACObject a;
    a.type = 12;
    a.l15 = to_string(numBytes);
    a.complete();

    TACContainer.insert(TACContainer.begin() + index, a);
    TACObject d;
    d.type = 13;
    d.l16 = "EndFunc";
    d.complete();
    TACContainer.push_back(d);
    
    inFunc = false;
    return "";
}

void FnDecl::PrintChildren(int indentLevel) {
    if (returnType) returnType->Print(indentLevel+1, "(return type) ");
    if (id) id->Print(indentLevel+1);
    if (formals) formals->PrintAll(indentLevel+1, "(formals) ");
    if (body) body->Print(indentLevel+1, "(body) ");
}


