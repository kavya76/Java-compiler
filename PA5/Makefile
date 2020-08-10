
.PHONY: clean strip


COMPILER = parser
PRODUCTS = $(COMPILER) 
default: $(PRODUCTS)

SRCS = ast.cc ast_decl.cc ast_expr.cc ast_stmt.cc ast_type.cc errors.cc utility.cc main.cc symtable.cc


OBJS = y.tab.o lex.yy.o $(patsubst %.cc, %.o, $(filter %.cc,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

JUNK =  *.o lex.yy.c dpp.yy.c y.tab.c y.tab.h *.core core *~


CC= g++
LD = g++
LEX = flex
YACC = bison


CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -std=c++11


LEXFLAGS = -d


YACCFLAGS = -dvty


LIBS = -lc -lm -ll



.yy.o: $*.yy.c
	$(CC) -std=c++11 $(CFLAGS) -c -o $@ $*.cc

lex.yy.c: lexer.l  parser.y y.tab.h 
	$(LEX) $(LEXFLAGS) lexer.l

y.tab.o: y.tab.c
	$(CC) -std=c++11 $(CFLAGS) -c -o y.tab.o y.tab.c

y.tab.h y.tab.c: parser.y
	$(YACC) $(YACCFLAGS) parser.y
.cc.o: $*.cc
	$(CC) -std=c++11 $(CFLAGS) -c -o $@ $*.cc


$(COMPILER) :  $(OBJS)
	$(LD) -std=c++11 -o $@ $(OBJS) $(LIBS)



strip : $(PRODUCTS)
	strip $(PRODUCTS)
	rm -rf $(JUNK)


depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

clean:
	rm -f $(JUNK) y.output $(PRODUCTS)

