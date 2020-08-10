
 #include "symtable.h"

SymbolTable::SymbolTable() {

    Scope initial_scope;
    initial_scope.is_loop = false;
    initial_scope.has_return = false;
    initial_scope.fn_name = "main";
    symtab_vec.push_back(initial_scope);
    current_scope = &(symtab_vec.back());  
 }

void SymbolTable::PushScope() {
    Scope new_scope;
    new_scope.has_return = false;
    new_scope.is_loop = current_scope->is_loop;
    new_scope.fn_name = current_scope->fn_name;
    symtab_vec.push_back(new_scope);
    current_scope = &(symtab_vec.back());
}

void SymbolTable::PopScope() {
    symtab_vec.pop_back();
    current_scope = &(symtab_vec.back());
}

void SymbolTable::AddSymbol(string name, Decl* decl_obj) {


    pair<map<string, Decl*>::iterator, bool> result;
    result = (current_scope->scope_map).insert(pair<string, Decl*>(name, decl_obj));

 
}

bool SymbolTable::IsInCurrentScope(string name) {
    return ( (current_scope->scope_map).count(name) != 0 );
}

bool SymbolTable::IsInAllScopes(string name) {
    bool result = false;

    for (int i = symtab_vec.size() - 1; i >= 0 ; i--)
    {
        if (symtab_vec[i].scope_map.count(name) != 0) result = true;
    }    

    return result;
}

Decl* SymbolTable::FindSymbolInCurrentScope(string name) {
    typedef map<string, Decl*>::const_iterator MapIterator;    
    for (MapIterator iter = (current_scope->scope_map).begin(); iter != (current_scope->scope_map).end(); iter++)
    {            
        if(iter->first == name) return iter->second;    
    }
    
    return NULL;
}

Decl* SymbolTable::FindSymbolInAllScopes(string name) {
    for (int i = symtab_vec.size() - 1; i >= 0 ; i--)
    {
        typedef map<string, Decl*>::const_iterator MapIterator;    
        for (MapIterator iter = symtab_vec[i].scope_map.begin(); iter != symtab_vec[i].scope_map.end(); iter++)
        {            
            if(iter->first == name) return iter->second;                            
        }
    }  

    return NULL;    
}

bool SymbolTable::HasReturn()
{
    return current_scope->has_return;
}

Scope * SymbolTable::GetScope()
{
    return current_scope;
}

void SymbolTable::Print()
{
    for (int i = symtab_vec.size() - 1; i >= 0 ; i--)
    {
        typedef map<string, Decl*>::const_iterator MapIterator;    
        for (MapIterator iter = symtab_vec[i].scope_map.begin(); iter != symtab_vec[i].scope_map.end(); iter++)
        {            
            std::cerr << i << "\t" << iter->first << std::endl;                        
        }
    }      
}
