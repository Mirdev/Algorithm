// Prints all prime numbers between two user-input integers using a boolean toggle method
#include <iostream>
using namespace std;

int main(){
	int in1=1, in2=300, i, j;
	bool s=true;

	cout << "1부터 300사이 정수 두개 입력 : ";
	cin >> in1;
	cin >> in2;

	for(i=in1+1 ; i<in2 ; i++){
		for(j=2 ; (j*j<=i)&&s ; j++){ 
			if(!(i%j))
				s = !s;
		}
		if(s)
			cout << i << endl;
		else
			s = !s;
	}
	return 0;
}
