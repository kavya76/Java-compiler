yacc -d try_symb.y
lex try_symb.l
gcc y.tab.c -ll -ly -w
echo "Please enter the testfile !"
read string
./a.out < $string.java
gcc outopt.c -w
./a.out

