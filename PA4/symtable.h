
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <iostream>
#include "ast_decl.h"
#include "ast_stmt.h"

struct Scope{
    map<string, Decl*> scope_map;
    string fn_name;
    bool has_return;
    bool is_loop;
};

class SymbolTable {
    protected:
        vector<Scope> symtab_vec;
        Scope *current_scope;

    public:
        SymbolTable();     
        void PushScope();
        void PopScope();
        void AddSymbol(string name, Decl* decl_obj);

        Scope * GetScope();
        bool HasReturn();
        bool IsInCurrentScope(string name);
        bool IsInAllScopes(string name);
        Decl* FindSymbolInCurrentScope(string name);
        Decl* FindSymbolInAllScopes(string name);
        void Print();
};
