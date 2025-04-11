// This program performs integer multiplication using bitwise shift and addition only.
// If the multiplier is not a power of two, the remainder is added manually.

#include <stdio.h>

void print_binary(int x) {
    for (int i = 31; i >= 0; i--)
        printf("%d", (x >> i) & 1);
}

int main() {
    int a, m, mul = 0;

    printf("Bitwise Multiplication Program\n\n");
    printf("//-- Notice --//\n");
    printf("This program uses only bitwise shifts to perform multiplication.\n");
    printf("//------------//\n\n");

    printf("Enter the multiplicand (a): ");
    scanf("%d", &a);
    printf("Enter the multiplier (m): ");
    scanf("%d", &m);

    int d = m;
    for (int i = 0; ; i++) {
        if (d == (1 << i)) {
            mul = a << i;
            break;
        }
        else if (d < (1 << i)) {
            d -= (1 << (i - 1));
            mul = a << (i - 1);
            for (int j = 0; j < d; j++) {
                mul += a;
            }
            break;
        }
    }

    printf("\nMultiplication result: %d\n", mul);
    printf("\n%-6d -> binary: ", a); print_binary(a);
    printf("\n%-6d -> binary: ", m); print_binary(m);
    printf("\n%-6d -> binary: ", mul); print_binary(mul);
    printf("\n");

    return 0;
}
