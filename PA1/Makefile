.PHONY: clean

LEXER = lexer
PRODUCTS = $(LEXER) $(PREPROCESSOR)
default: $(PRODUCTS)

SRCS = errors.cc


OBJS = lex.yy.o $(patsubst %.cc, %.o, $(filter %.cc,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

LIBS = -lc -lm -ll


CC= g++
LD = g++
LEX = flex

JUNK =  *.o lex.yy.c lexer y.output *~


CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare


LEXFLAGS = -d

lex.yy.c: lexer.l 
	$(LEX) $(LEXFLAGS) lexer.l

.cc.o: $*.cc
	$(CC) $(CFLAGS) -c -o $@ $*.cc

$(LEXER) : $(PREPROCESSOR) $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $(JUNK)  

