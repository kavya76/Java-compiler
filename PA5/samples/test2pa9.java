void main() {
    int a;
    int b;
    a = readIntFromSTDIN();
    b = readIntFromSTDIN();
    if (a < b) {
        printInt(b);
    }
    if (b < a) {
        printInt(a);
    }
}