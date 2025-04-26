// Triangular numbers and their sum
#include<iostream>
using namespace std;

int main() {
    int i, s = 0, n = 0;
    cin >> n;

    for(i = 1; i <= n; i++) {
        cout << i*(i+1)/2 << " ";
        s += i*(i+1)/2;
    }
    cout << endl;
    cout << s << endl;
    cout << (n*(n+1)*(2*n+1) + 3*n*(n+1)) / 12 << endl;
    cout << (n*n*n + 3*n*n + 2*n) / 6 << endl;

    return 0;
}
