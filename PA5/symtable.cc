#include "symtable.h"

 SymbolTable::SymbolTable() {
    Scope initial_scope;

    initial_scope.is_loop = false;
    initial_scope.is_switch = false;
    initial_scope.has_return = false;

    symtab_vec.push_back(initial_scope);
    current_scope = &(symtab_vec.back());
 }

 void SymbolTable::PushScope() {
    Scope new_scope;

    new_scope.is_loop = current_scope->is_loop;
    new_scope.is_switch = current_scope->is_switch;
    new_scope.has_return = false;

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


  Decl* SymbolTable::FindSymbolInCurrentScope(string name){

    typedef map<string, Decl*>::const_iterator MapIterator;    
    for (MapIterator iter = (current_scope->scope_map).begin(); iter != (current_scope->scope_map).end(); iter++)
    {            
        if(iter->first == name) return iter->second;    
    }
    
    return NULL;
  }


  Decl* SymbolTable::FindSymbolInAllScopes(string name){

    for (int i = symtab_vec.size() - 1; i >= 0 ; i--)
    {
        typedef map<string, Decl*>::const_iterator MapIterator;    
        for (MapIterator iter = symtab_vec[i].scope_map.begin(); iter != symtab_vec[i].scope_map.end(); iter++)
        {            
            if(iter->first == name) return iter->second;                            
        }
    }  

    // cout << "Cannot find symbol: " << name << " in SymbolTable::FindSymbolInAllScopes()!!!" << endl;
    return NULL;    
  }


  FnDecl* SymbolTable::GetCurrentFnDecl(){
    


    return current_scope->c_func_decl;
  }
  
  void SymbolTable::SetCurrentScopeIsLoop(bool isLoop){
    current_scope->is_loop = isLoop;
  }
  
  bool SymbolTable::IsInLoop(Stmt* statement){
    for(int i = symtab_vec.size() - 1; i >= 0; i--){
        if(symtab_vec[i].is_loop){
            return true;
        }
    }

    return false;
  }  

   bool SymbolTable::CurrentScopeIsLoop(){
        return current_scope->is_loop;
   }

  void SymbolTable::SetCurrentScopeIsSwitch(bool isSwitch){
    current_scope->is_switch = isSwitch;
  }
  
  bool SymbolTable::IsInSwitch(Stmt* statement){
    for(int i = symtab_vec.size() - 1; i >= 0; i--){
        if(symtab_vec[i].is_switch){
            return true;
        }
    }

    return false;
  }  

   bool SymbolTable::CurrentScopeIsSwitch(){
        return current_scope->is_switch;
   }

   
   void SymbolTable::SetCurrentScopeNaked(bool naked){
      current_scope->is_naked = naked;
   }
   
   bool SymbolTable::IsCurrentScopeNaked(){
      return current_scope->is_naked;
   }
   
  void SymbolTable::SetCurrentFnDeclHasReturn(){
    


    current_scope->has_return = true;

  }

   bool SymbolTable::IsCurrentScopeHasReturn(){
      return current_scope->has_return;
   }

   void SymbolTable::SetCurrentFnDecl(FnDecl* func_decl){
      current_scope->c_func_decl = func_decl;
   }


