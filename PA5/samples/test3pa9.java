void main() {
    int a = readIntFromSTDIN();
    int b = 7;
    int i;
    for (i = 0; i <= a; i++) {
        b += i;
    }
    printInt(b);
}