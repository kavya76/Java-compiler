
#ifndef _H_list
#define _H_list

#include <deque>
#include "utility.h" 
using namespace std;

class Node;

template<class Element> class List {

 private:
    deque<Element> elems;

 public:

    List() {}


    int NumElements() const
	{ return elems.size(); }

    Element Nth(int index) const
	{ Assert(index >= 0 && index < NumElements());
	  return elems[index]; }


    void InsertAt(const Element &elem, int index)
	{ Assert(index >= 0 && index <= NumElements());
	  elems.insert(elems.begin() + index, elem); }


    void Append(const Element &elem)
	{ elems.push_back(elem); }


    void RemoveAt(int index)
	{ Assert(index >= 0 && index < NumElements());
	  elems.erase(elems.begin() + index); }

    void SetParentAll(Node *p)
        { for (int i = 0; i < NumElements(); i++)
             Nth(i)->SetParent(p); }
    void PrintAll(int indentLevel, const char *label = NULL)
        { for (int i = 0; i < NumElements(); i++)
             Nth(i)->Print(indentLevel, label); }
             

};

#endif

