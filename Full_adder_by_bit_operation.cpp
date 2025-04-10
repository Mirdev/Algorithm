// Bitwise simulation of a full adder that adds two integers at the binary level.
// Simulates a full adder using only bitwise operations (no arithmetic operators).

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

void print_bin();
void print_dec();
int dec2bin(int x);

int i, n, a = 0, b = 0, menu = 0, d = 0;
int max_bit = 32;
int* fvalue = (int*)malloc(sizeof(int) * max_bit);

int main() {
    bool bin_a = 0, bin_b = 0, h1carry = 0, h2carry = 0, h1value = 0, carry;

    for (;;) {
        if (d != 0) {
            printf("\n1. Input numbers  2. Print in binary  3. Print in decimal (0. Exit)\n");
            printf("(Note: For option 3, only up to the maximum representable size of int is supported)\n");
            scanf("%d", &menu);
            system("cls");
        } else {
            menu = 1;
        }

        switch (menu) {
        case 0:
            break;
        case 1:
            n = -1;
            carry = 0;
            printf("Bitwise Full Adder Simulation\n");
            if (d == 0) {
                d = !d;
                printf("//== NOTICE ==//\n");
                printf("This project simulates bitwise full adder logic in pure C language.\n");
                printf("Memory is dynamically reallocated depending on the size of the input values,\n");
                printf("so the program does not rely on static allocation.\n");
                printf("(Note: Meant for CPU behavior-level simulation.)\n");
                printf("//==         ==//\n\n");
            }

            printf("Enter the first number -> ");
            scanf("%d", &a); fflush(stdin);

            // Dynamically adjust bit size based on the first input
            for (i = 0;; i++) {
                if (a < pow(2, i + 1)) {
                    max_bit = pow(2, i);
                    fvalue = (int*)malloc(sizeof(int) * max_bit);
                    break;
                }
            }

            printf("Enter the second number -> ");
            scanf("%d", &b); fflush(stdin);

            // If b is bigger, re-adjust bit size
            if (b > a) {
                for (i = 0;; i++) {
                    if (b < pow(2, i + 1)) {
                        max_bit = pow(2, i);
                        fvalue = (int*)malloc(sizeof(int) * max_bit);
                        break;
                    }
                }
            }

            for (i = 0; i < max_bit; i++) {
                n++;
                bin_a = dec2bin(a);
                bin_b = dec2bin(b);
                h1value = bin_b ^ carry;
                h1carry = bin_b && carry;
                *(fvalue + i) = bin_a ^ h1value;
                h2carry = bin_a && h1value;
                carry = h1carry || h2carry;
            }

            if (i == max_bit && carry == 1) {
                *(fvalue + i) = carry;
                // printf("Overflow detected. Result may exceed int range.\n");
            }
            break;
        case 2:
            print_bin();
            break;
        case 3:
            print_dec();
            break;
        }

        if (menu == 0)
            break;
    }

    free(fvalue);
    return 0;
}

void print_bin() {
    printf("Bitwise Full Adder Simulation\n");
    printf("\t\t\tcoded by Lyu\n\n");
    printf("Result in Binary Format --\n");

    printf("First input ->  ");
    for (i = 1; i < max_bit + 1; i++)
        printf("%d", ((a >> (max_bit - i)) & 0x01));
    printf(" (base-2)\n");

    printf("Second input -> ");
    for (i = 1; i < max_bit + 1; i++)
        printf("%d", ((b >> (max_bit - i)) & 0x01));
    printf(" (base-2)\n");

    if (*(fvalue + max_bit) == true) {
        printf("Addition Result -> ");
        for (i = max_bit; i > -1; i--)
            printf("%d", *(fvalue + i));
        printf("\t← Overflow detected.\n");
    } else {
        printf("Addition Result -> ");
        for (i = max_bit - 1; i > -1; i--)
            printf("%d", *(fvalue + i));
    }
    printf(" (base-2)\n");
}

void print_dec() {
    n = -1;
    int fir = 0, sec = 0, b2d = 0;
    printf("Bitwise Full Adder Simulation\n");
    printf("\t\t\tcoded by Lyu\n\n");
    printf("Result in Decimal Format --\n");

    for (i = 0; i < max_bit; i++) {
        n++;
        fir += dec2bin(a) * pow(2, i);
        sec += dec2bin(b) * pow(2, i);
    }

    printf("First input -> %d (base-10)\n", fir);
    printf("Second input -> %d (base-10)\n", sec);

    printf("Addition Result -> ");
    for (i = 0; i < max_bit; i++)
        b2d += *(fvalue + i) * pow(2, i);
    printf("%d (base-10)\n", b2d);
}

int dec2bin(int x) {
    if (n > max_bit)
        return 0;
    return ((x >> n) & 0x01);
}
