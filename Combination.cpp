# if input one number, then this program calculate all nCm

#include <iostream>
using namespace std;

int main() {
	double numerator=1, denominator=1, total=0;
	int i, j, n=0;
	cout << "num? : ";
	cin >> n;
	for(i=0 ; i<=n ; i++){
		for(j=0 ; j<i ; j++){
			numerator*=n-j;
			denominator*=j+1;
		}
		total+=numerator/denominator;
		cout << n << "C" << i << " : " << numerator/denominator << endl;
		numerator=1;
		denominator=1;
	}
	cout << "total : " << total << endl;
	return 0;
}
