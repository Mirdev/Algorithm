// Integer division using restoring division method.
// All arithmetic operations (add, sub, compare, divide) are implemented using only gate-level bitwise logic.
// No arithmetic operators (+, -, *, /, %, <, >, etc.) are used anywhere in computation logic.(except '--' in for loop)

#include <iostream>
using namespace std;

// Full-adder simulation using XOR and carry propagation.
// Not strictly bitwise, but performs correct addition via gate logic emulation.
int bit_add(int x, int y){
    while (y){
        int carry = x & y;       // Identify carry bits via AND
        x = x ^ y;               // Compute provisional sum via XOR
        y = carry << 1;          // Shift carries left for next round
    }
    return x;
}

// Two's complement subtraction: x - y = x + (~y + 1) [~y = y ^ -1]
int bit_sub(int x, int y){
    return bit_add(x, bit_add(y ^ -1, 1));
}

// Returns 1 if a ≥ b, otherwise returns 0
int bit_ge(int a, int b){
    int diff = bit_sub(a, b);        // Calculate a - b
    return ((diff >> 31) & 1) ^ 1;   // Extract sign bit and invert it
}

// Restoring division using only bitwise operations and custom gates
int bitwise_divide_gate(int dividend, int divisor, int &remainder) {
    if (divisor == 0){
        cout << "Division by zero." << endl;
        return 0;
    }

    int quotient = 0;
    remainder = 0;

    // Traverse from highest bit to lowest (31 to 0)
    for (int i = 31; i >= 0; i--){
        // Shift remainder left by 1 and bring in next bit of dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        // If remainder ≥ divisor, subtract and set quotient bit
        if (bit_ge(remainder, divisor)){
            remainder = bit_sub(remainder, divisor);
            quotient |= (1 << i);
        }
    }
    return quotient;
}

int main(){
    int a, b;
    cout << "Enter dividend : ";
    cin >> a;
    cout << "Enter divisor  : ";
    cin >> b;

    int rem = 0;
    int q = bitwise_divide_gate(a, b, rem);

    cout << "Quotient  = " << q << '\n';
    cout << "Remainder = " << rem << '\n';

    return 0;
}
