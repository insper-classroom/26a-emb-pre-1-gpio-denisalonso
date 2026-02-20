#include "stdio.h"
int foo(a) {
    a = a + 1; // acessa variavel global
    return a;
}

void main(void) {
    int a = 0; // var global
    int b = 0; // var global
    int i = 0;
    while (i < b) {
        foo(a);
        
        if (a > 5) {
            b = 1;
        }
    }
}
