#include <stdio.h>

extern int add(int a, int b);

int main() {
    int x = add(2, 3);
    printf("%d\n", x);
    return 0;
}
