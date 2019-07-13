// This program is insertion sort program.
// Now file input and output system is commented. If you want to use file IO system, then delete all commentation marks.

#include<iostream>
#include<time.h>
using namespace std;

void rand_arr();
void print_arr(int);
void insertion_sort();
void arr_copy(int);

#define ORIGINE 0
#define INSERTION 3
#define NSIZE 100
#define SIZE 150000

//FILE *fp;
clock_t t;
int a[SIZE]={0,}, sel[SIZE], ins[SIZE], i, j, tmp;

int main(){
	srand((unsigned)time(NULL));

	rand_arr();
	print_arr(ORIGINE);

	insertion_sort();			
	print_arr(INSERTION);

	return 0;
}

void insertion_sort(){
	arr_copy(INSERTION);
	cout << "Start insertion sorting.\n";
	t=clock();
	for(i=0 ; i<SIZE ; i++){
		if(ins[i]>ins[i+1]&&i+1<SIZE){
			tmp=ins[i+1];
			for(j=i ; j>-1 ; j--){
				if(ins[j]>tmp){
					ins[j+1]=ins[j];
					if(j<1){
						ins[j]=tmp;
						break;
					}
					else if(ins[j-1]<=tmp){
						ins[j]=tmp;
						break;
					}
				}
			}
		}
	}
	cout << "Complete insertion sorting.\n";
	cout << "Time taking : " << (clock()-t)/CLOCKS_PER_SEC << endl;
}

void arr_copy(int x){
	cout << "Copy the array.\n";
	switch(x){
		case SELECTION:
			for(i=0 ; i<SIZE ; i++)
				sel[i]=a[i];
			break;
		case INSERTION:
			for(i=0 ; i<SIZE ; i++)
				ins[i]=a[i];
			break;
	}
	cout << "Complete about copy.\n";
}

void rand_arr(){
	int r, x;
	bool f=false;

	cout << "Initialize the array.\n";

	for(i=0 ; i<SIZE ; i++)
		a[i]=0;

	cout << "Randomization method[1.Allow repetition(fast) 2.DO NOT allow repetition(slow) 3.Partial randomization] : ";
	cin >> x;

	cout << "Randomization.\n";
	t=clock();

	switch(x){
		case 1:
			cout << "Randomization with allowing repetition.\n";
			for(i=0 ; i<SIZE ; i++)
				a[i]=rand()%SIZE+1;
			break;
		case 2:
			cout << "Randomization with non-allowing repetition\n";
			for(i=1 ; !f ; i+=(rand()%5)+1){
				for(int k=0 ; k<SIZE ; k++){
					if(!a[k]){
						f=false;
						break;
					}
					else
						f=true;
				}
				r=rand()%SIZE;
				if(!a[r])
					a[r]=i;
				else
					i--;
			}
			break;
		case 3:
			cout << "Randomization with partial randomization.\n";
			for(i=0 ; i<SIZE ; i++)
				a[i]=i+1;
			for(i=0 ; i<SIZE/NSIZE ; i++){
				r=rand()%SIZE;
				tmp=a[r];
				a[r]=a[SIZE-r-1];
				a[SIZE-r-1]=tmp;
			}
			break;
	}

	cout << "Complete of randomization. ";
	cout << "time taking : " << (clock()-t)/CLOCKS_PER_SEC << '\n' << endl;
	/*cout << "Do you want to save to file?(y/n)";
	cin >> x;
	switch(x){
		case 'Y':
		case 'y':
			cout << "File saving.\n";
			fp=fopen("rand_arr.txt", "w+");
			for(i=0 ; i<100 ; i++)
				fprintf(fp,"%d ",a[i]);
			fclose(fp);
			cout << "Saving complete.\n\n";
		case 'N':
		case 'n':
			cout << "Move to next step.\n\n";
	}*/
}

void print_arr(int x){
	cout << "Prin array.\n";
	for(i=0 ; i<SIZE ; i++){
		switch(x){
			case ORIGINE:
			case BUBBLE:
				cout << a[i] << " ";
				break;
			case SELECTION:
				cout << sel[i] << " ";
				break;
			case INSERTION:
				cout << ins[i] << " ";
				break;
		}
	}
	cout << endl;
	cout << "Printing compete.\n\n";
}
