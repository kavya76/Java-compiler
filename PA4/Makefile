
.PHONY: clean strip


COMPILER = glc
PRODUCTS = $(COMPILER) 
default: $(PRODUCTS)

SRCS = ast.cc ast_decl.cc ast_expr.cc ast_stmt.cc ast_type.cc errors.cc utility.cc main.cc symtable.cc

OBJS = y.tab.o lex.yy.o $(patsubst %.cc, %.o, $(filter %.cc,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

JUNK =  *.o lex.yy.c dpp.yy.c y.tab.c y.tab.h *.core core *~

CC= g++
LD = g++
LEX = flex
YACC = bison


CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare

LEXFLAGS = -d

YACCFLAGS = -dvty



LIBS = -lc -lm -ll



.yy.o: $*.yy.c
	$(CC) $(CFLAGS) -c -o $@ $*.cc

lex.yy.c: lexer.l  parser.y y.tab.h 
	$(LEX) $(LEXFLAGS) lexer.l

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c -o y.tab.o y.tab.c

y.tab.h y.tab.c: parser.y
	$(YACC) $(YACCFLAGS) parser.y
.cc.o: $*.cc
	$(CC) $(CFLAGS) -c -o $@ $*.cc



$(COMPILER) :  $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS)


strip : $(PRODUCTS)
	strip $(PRODUCTS)
	rm -rf $(JUNK)


#
depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

clean:
	rm -f $(JUNK) y.output $(PRODUCTS)

