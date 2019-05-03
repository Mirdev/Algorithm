#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

bool iskn(int,int);

int main(){
	clock_t stt=clock();
	unsigned int i, k;
	int j=1;
	for(i=1 ; i<4294967295 ; i++){
		for(j=0, k=i ; k>0 ; j++, k/=10);
		if(j%2)
			continue;
		if(iskn(i,j)){
			cout << i << '\t';
			cout << (clock()-stt)/CLOCKS_PER_SEC << endl;
			stt=clock();
		}
	}
	return 0;
}

bool iskn(int x, int y){
	unsigned int m=x, n=0;
	n=m%(int)pow(10.,y/2);
	m/=pow(10.,y/2);
	if((n+m)*(n+m)==x)
		return true;
	return false;
}
