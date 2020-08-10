
#ifndef _errors_h_
#define _errors_h_

#include <string>
#include "location.h"
#include "ast_decl.h"

using namespace std;



class Type;
class Identifier;
class Expr;
class BreakStmt;
class ReturnStmt;
class Decl;
class Operator;

typedef enum {
      LookingForType,
      LookingForVariable,
      LookingForFunction
} reasonT;

class ReportError {
 public:


  static void UntermComment(); 
  static void LongIdentifier(yyltype *loc, const char *ident);
  static void UntermString(yyltype *loc, const char *str);
  static void UnrecogChar(yyltype *loc, char ch);


  static void DeclConflict(Decl *newDecl, Decl *prevDecl);
  static void InvalidInitialization(Identifier *id, Type *lType, Type *rType);
  
  

  static void IdentifierNotDeclared(Identifier *ident, reasonT whyNeeded);

  static void NotAnArray(Identifier *id);
              
  static void IncompatibleOperand(Operator *op, Type *rhs);
  static void IncompatibleOperands(Operator *op, Type *lhs, Type *rhs); 

  static void ExtraFormals(Identifier *id, int expCount, int actualCount); 
  static void LessFormals(Identifier *id, int expCount, int actualCount); 
  static void FormalsTypeMismatch(Identifier *id, int pos, Type *expType, Type *actualType); 
  static void NotAFunction(Identifier *id); 
  
  static void InaccessibleSwizzle(Identifier *swizzle, Expr *base);
  static void InvalidSwizzle(Identifier *swizzle, Expr *base);
  static void SwizzleOutOfBound(Identifier *swizzle, Expr *base);
  static void OversizedVector(Identifier *swizzle, Expr *base);
  
  static void TestNotBoolean(Expr *testExpr);
  static void ReturnMismatch(ReturnStmt *rStmt, Type *given, Type *expected);
  static void ReturnMissing(FnDecl *fnDecl);
  static void BreakOutsideLoop(BreakStmt *bStmt); 

  static void Formatted(yyltype *loc, const char *format, ...);


  static int NumErrors() { return numErrors; }
  
 private:
  static void UnderlineErrorInLine(const char *line, yyltype *pos);
  static void OutputError(yyltype *loc, string msg);
  static int numErrors;
};
#endif
