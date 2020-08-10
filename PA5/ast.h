
#ifndef _H_ast
#define _H_ast

#include <stdlib.h>  
#include <iostream>
#include <string>
#include "location.h"
#include <vector>
#include <set>
#include <stdio.h>
#include <map>

using namespace std;
class SymbolTable;

struct TACObject{
    int type;
    string l0;
    //2 is action and action item,
    string acname;
    string acitem;
    //3 is is branch (if "t1" goto "label")
    string l1;//t1
    string l2;//label
    //4 destination, source1 source 2
    string dest;
    string s1;
    string s2;
    //5 jump, example ("goto l1")
    string l3;
    //6 return statement
    string ret;
    //7 function call: t1 call foo 5params
    string l4; //t1
    string func;
    int np;//number of params
    //8 logical expr or relational or equality
    string l5;//t1
    string l6;//leftstring
    string op;
    string l7;//rightString
    //9 assignment expr
    string l8;
    string l9;
    //10 postfix
    string l10;
    string addsub;
    //11 arithemticexpr
    string l11;
    string l12;
    string op1;
    string l13;
    string l15;
    //13 endfunc
    string l16;
    //14 var decl
    string l17;
    string l18;
    string IF = "if ";
    string GOTO = " goto ";
    string complete1 ;
    string complete2 ;
    string complete3 ;
    string complete5 ;
    string complete6 ;
    string complete7 ;
    string complete8 ;
    string complete9 ;
    string complete10;
    string complete11;
    string complete12;
    string complete13;
    string complete14;
    void complete(){
        complete1 = l0 + ":";
        complete2 = "    " + acname + " " + acitem; 
        complete3 = "    " + IF + l1 + GOTO + l2;
        complete5 = "   " + GOTO + l3;
        complete6 = "    Return " + ret;
        complete7 = "    " + l4 + " call " + func + " ";
        complete8 = "    " + l5 + " := " + l6 +" " + op +" " + l7;
        complete9 = "    " + l8 + " := " + l9;
        complete10 ="    " + l10 + " := " + l10 + addsub;
        complete11 ="    " + l11+ " := " + l12 + " " + op1 + " " + l13;
        complete12 ="    BeginFunc " + l15;
        complete13 ="    " + l16;
        complete14 ="    " + l17 + " =: " + l18;
    }
};

class Node  {
  protected:
    yyltype *location;
    Node *parent;
    static SymbolTable *symtab;
    static int registerCounter;
    static int labelCounter;
    static int varCounter;
    static int mipsReg;
    static vector<TACObject> TACContainer;
    static set<string> localVars;
    static map<string, bool> globalVars;
    static bool inFunc;
    static map<string, int> propMap;
    static map<string, bool> deadMap;
    static map<string, string> mipsMap;

  public:
    Node(yyltype loc);
    Node();
    virtual ~Node() {}
    
    yyltype *GetLocation()   { return location; }
    void SetParent(Node *p)  { parent = p; }
    Node *GetParent()        { return parent; }

    virtual const char *GetPrintNameForNode() = 0;
    void Print(int indentLevel, const char *label = NULL); 
    virtual void PrintChildren(int indentLevel)  {}
    virtual string Emit();
};
   

class Identifier : public Node 
{
  protected:
    char *name;
    
  public:
    Identifier(yyltype loc, const char *name);
    const char *GetPrintNameForNode()   { return "Identifier"; }
    void PrintChildren(int indentLevel);
    char *GetName() const { return name; }
};


class Error : public Node
{
  public:
    Error() : Node() {}
    const char *GetPrintNameForNode()   { return "Error"; }
};

#endif
