// Permutation generator: outputs to console, file, or both
// Simple permutation printer with output options
// Prints all permutations of input characters (console/file)

#include<iostream>
using namespace std;

#define MAX 100
char buf[MAX]={0,};
char per[MAX]={0,};

int num[MAX]={0,};
bool occ[MAX]={0,};
int n=0, m=1, size=0;

void TD(int);
void arysiz(char[]);
void input(char[]);

FILE *fp;

int main(){
	fp=fopen("result.txt", "w+");
	cout << "Input elements for permutation (split by using space or ,) : ";
	cin >> buf;fflush(stdin);
	input(buf);
	arysiz(per);
	while(1){
		cout << "print: 1.only monitor 2.only file 3.both of monitor and file" << endl;
		cin >> m;fflush(stdin);
		system("cls");
		if(m<1 || m>3)
			cout << "*** You should select between 1-3. ***\n" << endl;
		else
			break;
	}
	if(m==2)
		cout << "Printing..." << endl;
	TD(0);
	if(m==2){
		system("cls");
		cout << "Print completed." << endl;
	}
	if(m!=1)
		fprintf(fp, "%d", n);
	if(m!=2)
		cout << n << endl;
	fclose(fp);
	return 0;
}

void TD(int j){
	int x;
	if(j==::size){
		for(x=0 ; x<::size ; x++){
			if(m!=1)
				fprintf(fp, "%c", per[num[x]]);
			if(m!=2)
				cout << per[num[x]];
		}
		if(m!=1)
			fprintf(fp, "\n");
		if(m!=2)
			cout << endl;
		n++;
		j--;
	}
	for(x=0 ; x<::size ; x++){
		if(occ[x]==true)
			continue;
		num[j]=x;
		occ[num[j]]=true;
		TD(j+1);
		occ[num[j]]=false;
	}
}

void arysiz(char x[]){
	int i;
	for(i=0 ; x[i] ; i++)
		::size++;
}

void input(char x[]){
	int i, n=0;
	for(i=0 ; x[i] ; i++)
		if(x[i]!=','){
			per[n]=x[i];
			n++;
		}
}


// Below is legacy reference: 
// Non-recursive brute-force version that exhaustively generates permutations using nested loops.
// Served as the conceptual basis for the recursive permutation logic above.
/*
#include<iostream>
using namespace std;

#define MAX 5

int main(){
	int i, j, k, l, m, n=0;
	int str[MAX]={1,2,3,4,5};
	int tmp[MAX]={0,};
	for(i=0 ; i<5 ; i++){
		tmp[i]=-1;
		for(j=0 ; j<5 ; j++){
			if(tmp[j]==-1)
				continue;
			tmp[j]=-1;
			for(k=0 ; k<5 ; k++){
				if(tmp[k]==-1)
					continue;
				tmp[k]=-1;
				for(l=0 ; l<5 ; l++){
					if(tmp[l]==-1)
						continue;
					tmp[l]=-1;
					for(m=0 ; m<5 ; m++){
						if(tmp[m]==-1)
							continue;
						cout << str[i] << str[j] << str[k] << str[l] << str[m] << endl;
						n++;
					}
					tmp[l]=0;
				}
				tmp[k]=0;
			}
			tmp[j]=0;
		}
		tmp[i]=0;
	}
	cout << n << endl;
	return 0;
}
*/
