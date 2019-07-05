#include<iostream>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;

int main(){
	int f, s, j, k, i;
	cout << setprecision(100);
	for(j=0 ; j<20 ; j++){
		for(s=1 ; 25*pow(10.,2*j)-(pow(10.,j+1)-1)*s>0 ; s++){
			f=25*pow(10.,2*j)-(pow(10.,j+1)-1)*s;
			if((int)sqrt((double)f)*(int)sqrt((double)f)==f){
				k=((5*pow(10.,j)-s)-sqrt((double)f))*pow(10.,j+1)+s;
				for(i=0;k>0;i++,k/=10);
				cout << j+1 << " " << ((5*pow(10.,j)-s)+sqrt((double)f))*pow(10.,j+1)+s << endl;
				if(!(i%2))
					cout << j+1 << " " << ((5*pow(10.,j)-s)-sqrt((double)f))*pow(10.,j+1)+s << endl;
			}
		}
	}
	return 0;
}
