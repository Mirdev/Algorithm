#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

bool iskn(int,int);

int main(){
	clock_t stt=clock();
	unsigned int i;
	int j=1;
	for(i=1 ; i<4294967295 ; i++){
		if(!(i%(int)pow(10.,j)))
			j++;
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
