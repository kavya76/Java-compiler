

#include <string.h>
#include "ast_type.h"
#include "ast_decl.h"
 


Type *Type::intType    = new Type("int");
Type *Type::voidType   = new Type("void");
Type *Type::boolType   = new Type("boolean");
Type *Type::errorType  = new Type("error"); 
Type *Type::bvec4Type = new Type("bvec4");

Type::Type(const char *n) {
    Assert(n);
    typeName = strdup(n);
}

void Type::PrintChildren(int indentLevel) {
    printf("%s", typeName);
}

bool Type::IsNumeric() { 
    return this->IsEquivalentTo(Type::intType);
}

bool Type::IsError() { 
    return this->IsEquivalentTo(Type::errorType);
}
	
NamedType::NamedType(Identifier *i) : Type(*i->GetLocation()) {
    Assert(i != NULL);
    (id=i)->SetParent(this);
} 

void NamedType::PrintChildren(int indentLevel) {
    id->Print(indentLevel+1);
}
