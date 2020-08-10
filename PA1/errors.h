
#ifndef _errors_h_
#define _errors_h_

#include <string>
#include "location.h"
using namespace std;
class ReportError {
 public:
  static void UntermComment(); 
  static void LongIdentifier(yyltype *loc, const char *ident);
  static void UntermString(yyltype *loc, const char *str);
  static void UnrecogChar(yyltype *loc, char ch);
  static void Formatted(yyltype *loc, const char *format, ...);

  static int NumErrors() { return numErrors; }
  
 private:
  static void UnderlineErrorInLine(const char *line, yyltype *pos);
  static void OutputError(yyltype *loc, string msg);
  static int numErrors;
};
#endif
