#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"


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
	Assert(i != NULL && t != NULL && s != NULL && b != NULL);
	(init=i)->SetParent(this);
	(step=s)->SetParent(this);
}

void ForStmt::PrintChildren(int indentLevel) {
	init->Print(indentLevel+1, "(init) ");
	test->Print(indentLevel+1, "(test) ");
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
	Assert(e != NULL);
	(expr=e)->SetParent(this);
}

void ReturnStmt::PrintChildren(int indentLevel) {
	expr->Print(indentLevel+1);
}

DeclStmt::DeclStmt(yyltype loc, Decl *decl) : Stmt(loc) {
	Assert(decl != NULL);
	(varDecl=decl)->SetParent(this);
}

void DeclStmt::PrintChildren(int indentLevel) {
	varDecl->Print(indentLevel+1);
}

string Program::Emit() {
	if ( decls->NumElements() > 0 ) {
		for ( int i = 0; i < decls->NumElements(); ++i ) {
			Decl *d = decls->Nth(i);
			d->Emit();
		}
	}


	vector<TACObject> optimized_TACContainer = TACContainer;
	for (int i = 0; i < optimized_TACContainer.size(); i++) {
		int t = optimized_TACContainer[i].type;
		if (t != 12) {
			cout << generateMipsCode(optimized_TACContainer[i], t) << endl;
		}
	}
	return "Program::Emit()";
}

string Program::generateMipsCode(TACObject TACobj, int t) {
	//t = TACobj.type;
	string temp;
	string temp3;
	switch(t) {
		case 1: return TACobj.complete1;
			break;
		case 2: return 	"    li $v0, 1\n    move $a0, " + mipsMap[TACobj.acitem] + "\n    syscall";
						//TACobj.complete2;
			break;
		case 3: return 	"    beq $t" + to_string(mipsReg-1) + ", $zero, " + TACobj.l2;
						//TACobj.complete3;
			break;
		case 5: return 	"    j " + TACobj.l3;
						//TACobj.complete5;
			break;
		case 6: return 	"complete6";
						//TACobj.complete6;
			break;
		case 7: return  "    li $v0, 5\n    syscall";
						//TACobj.complete7;
			break;
		case 8: return 	"    slt $t" + to_string(mipsReg++) + 
						", " + mipsMap[TACobj.l7] + ", " + mipsMap[TACobj.l6];
						//TACobj.complete8;
			break;
		case 9: temp = "$t" + to_string(mipsReg++);
				mipsMap[TACobj.l8] = temp;
				temp3 = mipsMap.find(TACobj.l8)==mipsMap.end() ? mipsMap[TACobj.l8] : "$v0";

				return 	"    move " + temp + ", " + temp3;
				//return TACobj.complete9;
			break;
		case 10: return //"    ";
						TACobj.complete10;
			break;
		case 11: return "complete11";
						//TACobj.complete11;
			break;
		case 12: return "complete12";
						//TACobj.complete12;
			break;
		case 13: return "    li $v0, 10\n    syscall";
						//TACobj.complete13;
			break;
		case 14: 	temp = "$t" + to_string(mipsReg++);
					mipsMap[TACobj.l17] = temp;
					int temp2 = mipsMap.find(TACobj.l18)==mipsMap.end() ? atoi(mipsMap[TACobj.l18].c_str()) : 0;
					return "    li " + temp + ", " + to_string(temp2);
					//TACobj.complete14;
			break;
	}
	return "";
}

vector<TACObject> Program::constantFolding(vector<TACObject> TACContainer) {
	for (int i = 0; i < TACContainer.size(); i++) {
		TACObject obj = TACContainer[i];
		if (obj.type == 11) {
			//l12 op1 l13
			int left = atoi(obj.l12.c_str());
			int right = atoi(obj.l13.c_str());
			string oper = obj.op1;
			if (left > 0 && right > 0) {
				int result = 0;
				if (oper == "*") {
					result = left * right;
				}
				else if (oper == "/") {
					result = left / right;
				}
				else if (oper == "+") {
					result = left + right;
				}
				else if (oper == "-") {
					result = left - right;
				}
				TACContainer[i].type = 14;
				TACContainer[i].l17 = obj.l11;
				TACContainer[i].l18 = to_string(result);
				TACContainer[i].complete();
			}
		}
	}
	return TACContainer;
}

vector<TACObject> Program::constantPropogation(vector<TACObject> TACContainer) {
	for (int i = 0; i < TACContainer.size(); i++) {
		if(TACContainer[i].type == 14){
			//string check1 = TACContainer[i].l17;
			string check2 = TACContainer[i].l18;
			//cout << "propmap[" << check1 << "] = " << propMap[check1] << endl;
			if(propMap[check2]){
				cout<<"in here"<<endl;
				TACContainer[i].l18 = to_string(propMap[check2]);
				TACContainer[i].complete();
			}
			else{
				propMap.insert(pair<string,int>(TACContainer[i].l17, atoi(TACContainer[i].l18.c_str() ) ) );
			}
		}
		else if(TACContainer[i].type == 11){
			string check1 = TACContainer[i].l12;
			string check2 = TACContainer[i].l13;

			if (propMap[check1])
			{
				TACContainer[i].l12 = to_string(propMap[check1]);
				cout << "propmap[" << check1 << "] = " << propMap[check1] << endl;
			}
			else{
				cout << check1 << " is not in map!" << endl;
			}
			if (propMap[check2])
			{
				TACContainer[i].l13 = to_string(propMap[check2]);

				cout << "propmap[" << check2 << "] = " << propMap[check2] << endl;
			}
			else{
				cout << check1 << " is not in map!" << endl;
			}
			TACContainer[i].complete();
			// propMap.insert(pair<string,int>(TACContainer[i],99));

		}
		else if(TACContainer[i].type == 9){
			string check1 = TACContainer[i].l9;
			if(propMap[check1]){
				TACContainer[i].l9 = to_string(propMap[check1]);
				TACContainer[i].complete();
			}
		}
	}

	return TACContainer;
}

vector<TACObject> Program::deadCodeElimination(vector<TACObject> TACContainer) {

	for (int i = 0; i < TACContainer.size(); i++) {
		//cout << TACContainer[i].type << endl;
		if (TACContainer[i].type == 14){
			deadMap.insert(pair<string, bool>(TACContainer[i].l17, true));
		}
		else if(TACContainer[i].type == 9){
			string check1 = TACContainer[i].l8;
			if(deadMap[check1]) {
				deadMap[check1] = false;
			}
			else
			{
				TACContainer.erase(TACContainer.begin() + i - 1);
			}

		}
	}

	return TACContainer;
}

string StmtBlock::Emit() {
	for(int i = 0; i < stmts->NumElements(); i++){
		Stmt* ith_statement = stmts->Nth(i); 
		ith_statement->Emit();
	}

	return "StmtBlock::Emit()";
}

string ForStmt::Emit() {
	TACObject a;//label 0
	a.type = 1;
	a.l0 = "L" + to_string(labelCounter);
	labelCounter++;

	TACObject j;//label 1
	j.type = 1;
	j.l0 = "L" + to_string(labelCounter);
	labelCounter++;

	TACObject k;//label 2
	k.type = 1;
	k.l0 = "L" + to_string(labelCounter);
	labelCounter++;

	
	init->Emit();
	a.complete();
	TACContainer.push_back(a);
		
	TACObject b;
	b.type=3;
	string condition = test->Emit();	
	b.l1 = condition;
	b.l2 = j.l0;
	b.complete();
	TACContainer.push_back(b);
	
	TACObject q;
	q.type = 5;
	q.l3 = k.l0;
	q.complete();
	TACContainer.push_back(q);

	j.complete();
	TACContainer.push_back(j);

	body->Emit();
	step->Emit();
		
	TACObject c;
	c.type = 5;
	c.l3 = a.l0;
	c.complete();
	TACContainer.push_back(c);

	TACObject d;
	d.type = 1;
	d.l0 = k.l0;
	d.complete();
	TACContainer.push_back(d);

	return "ForStmt::Emit()";
}

string WhileStmt::Emit() {
string L0 = "L" + to_string(labelCounter);
	labelCounter++;
	string L1 = "L" + to_string(labelCounter);
	labelCounter++;
	string L2 = "L" + to_string(labelCounter);
	labelCounter++;

	//l0
	TACObject a;//label
	a.type = 1;
	a.l0 = L0;
	a.complete();
	TACContainer.push_back(a);
	
	//if t1 goto l1
	TACObject b;
	b.type=3;
	string condition = test->Emit();	
	b.l1 = condition;
	b.l2 = L1;
	b.complete();
	TACContainer.push_back(b);

	//goto l1
	TACObject c;
	c.type = 5;
	c.l3 = L2;
	c.complete();
	TACContainer.push_back(c);

	//l1
	TACObject z;
	z.type = 1;
	z.l0 = L1;
	z.complete();
	TACContainer.push_back(z);

	body->Emit();
	
	//
	TACObject e;
	e.type = 5;
	e.l3 = L0;
	e.complete();
	TACContainer.push_back(e);
	

	TACObject d;
	d.type = 1;
	d.l0 =L2;
	d.complete();
	TACContainer.push_back(d);

	return "WhileStmt";
}

string IfStmt::Emit() {
string condRes = test->Emit();
	
	string labelString1 = "L" + to_string(labelCounter++);
	string labelString2 = "L" + to_string(labelCounter++);
	if(elseBody)
	{
		string labelString3 = "L" + to_string(labelCounter++);
		
		TACObject a;
		a.type = 3;
		a.l1 = condRes;
		a.l2 = labelString1;
		a.complete();
		TACContainer.push_back(a);

		TACObject b;
		b.type = 5;
		b.l3 = labelString2;
		b.complete();
		TACContainer.push_back(b);

		TACObject c;
		c.type = 1;
		c.l0 = labelString1;
		c.complete();
		TACContainer.push_back(c);
		
		body->Emit();

		TACObject d;
		d.type = 5;
		d.l3 = labelString3;
		d.complete();
		TACContainer.push_back(d);
		
		TACObject e;
		e.type = 1;
		e.l0 = labelString2;
		e.complete();
		TACContainer.push_back(e);
		
		elseBody->Emit();

		TACObject f;
		f.type = 5;
		f.l3 = labelString3;
		f.complete();
		TACContainer.push_back(f);
		
		TACObject g;
		g.type = 1;
		g.l0 = labelString3;
		g.complete();
		TACContainer.push_back(g);	
	}
	else
	{
		TACObject a;
		a.type = 3;
		a.l1 = condRes;
		a.l2 = labelString1;
		a.complete();
		TACContainer.push_back(a);

		TACObject b;
		b.type = 5;
		b.l3 = labelString2;
		b.complete();
		TACContainer.push_back(b);
		
		TACObject c;
		c.type = 1;
		c.l0 = labelString1;
		c.complete();
		TACContainer.push_back(c);

		body->Emit();

		TACObject d;
		d.type = 5;
		d.l3 = labelString2;
		d.complete();
		TACContainer.push_back(d);
		
		TACObject e;
		e.type = 1;
		e.l0 = labelString2;
		e.complete();
		TACContainer.push_back(e);
	}
	return "IFstatement";
}

string ReturnStmt::Emit() {
	TACObject a;
	a.type = 6;
	string ret = expr->Emit();
	//optimized_TACContainer.push_back(string("    ") + string("Return ") + ret);
	a.ret = ret;
	a.complete();
	TACContainer.push_back(a);
	
	return "ReturnStmt Emit()";
}

string DeclStmt::Emit() {
	varDecl->Emit();
	return "DeclStmt Emit()";
}
