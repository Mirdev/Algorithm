// Greedy search method(one by one simulation)

#include<iostream>
using namespace std;

#define Queen '@'
#define Block '.'
#define MOF 8

int field[MOF][MOF]={0,}, l=0, c=0, q_count;
int maxc;

void fst_trn(), init(), queen(), block(int x, int y), print();

int main(){
	cout << MOF << " * " << MOF << endl;
	for(c=0 ; c<MOF ; c++){
		for(l=0 ; l<MOF ; l++){
			init();
			fst_trn();
			queen();
			if(q_count>maxc-1){
				maxc=q_count;
			}
		}
	}
	cout << maxc << endl;
	for(c=0 ; c<MOF ; c++){
		for(l=0 ; l<MOF ; l++){
			init();
			fst_trn();
			queen();
			if(q_count>maxc-1){
				print();
			}
		}
	}
	return 0;
}

void init(){
	q_count=0;
	for(int i=0, j ; i<MOF ; i++){
		for(j=0 ; j<MOF ; j++){
			field[j][i]=0;
		}
	}
}

void fst_trn(){
	field[l][c]=Queen;
	block(l, c);
	q_count++;
}

void queen(){
	for(int i=0, j ; i<MOF ; i++){
		for(j=0 ; j<MOF ; j++){
			if(field[j][i]!=Queen && field[j][i]!=Block){
				field[j][i]=Queen;
				block(j, i);
				q_count++;
			}
		}
	}
}

void block(int x, int y){
	for(int j=0 ; j<MOF ; j++)			//���� ����
		if(field[j][y]==0)
			field[j][y]=Block;
	for(int i=0 ; i<MOF ; i++)			//���� ����
		if(field[x][i]==0)
			field[x][i]=Block;
	for(int f=0 ; f<MOF ; f++){			//�밢 ����
		if(x+f<MOF && y+f<MOF){
			if(field[x+f][y+f]==0)
				field[x+f][y+f]=Block;
		}
		if(x-f>-1 && y+f<MOF){
			if(field[x-f][y+f]==0)
				field[x-f][y+f]=Block;
		}
		if(x+f<MOF && y-f>-1){
			if(field[x+f][y-f]==0)
				field[x+f][y-f]=Block;
		}
		if(x-f>-1 && y-f>-1){
			if(field[x-f][y-f]==0)
				field[x-f][y-f]=Block;
		}
	}
}

void print(){
	cout << "Queen's Number : " << maxc << endl;
	for(int i=0, j ; i<MOF ; i++){
		for(j=0 ; j<MOF ; j++){
			cout << ' ' << static_cast<char>(field[j][i]);
		}
		cout << endl;
	}
	cout << endl;
}
