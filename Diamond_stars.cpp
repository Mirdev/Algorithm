// Print diamond shape stars with just 3 for loop
// SIZE must be odd natural number.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int SIZE = 5;

  for(int i=-SIZE/2; i<SIZE/2+1; i++){
    for(int j=0; j<abs(i); j++)
        cout << " ";
    for(int j=0; j<SIZE-2*abs(i); j++)
        cout << "*";
    cout << endl;
  }
}
