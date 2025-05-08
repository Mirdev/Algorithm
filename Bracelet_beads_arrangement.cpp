// This program checks if selected beads can form a closed bracelet and rearranges them accordingly.
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int alphabet[26] = { 0, }, num, i, j;
	char beads[100][4] = { 0, }, tmp[4] = { 0, }, yn = 'y';
	bool s = true;
	while (1){
		for (i = 0; i < 27; i++) { alphabet[i] = 0; }
		cout << "Insert the number of bead you're gonna choose(5~100): ";
		cin >> num;
		fflush(stdin);
		cout << "Insert two colors of each bead (" << num << ")" << endl;
		for (i = 0; i < num; i++){
			cout << "=> " << i + 1 << ". : ";
			cin.getline(beads[i], 4);
			fflush(stdin);
			beads[i][0] = tolower(beads[i][0]);
			beads[i][2] = tolower(beads[i][2]);
			if (!((beads[i][0]<123 && beads[i][0]>96) && (beads[i][2]<123 && beads[i][2]>96))){
				cout << "Colors are a~z, 26 only. Reinput plz" << endl;
				i--;
				continue;
			}
			for (j = 0; j < 3; j += 2){
				alphabet[beads[i][j] - 97]++;
			}
		}
		cout << "\nThis is YOUR BEADS you picked." << endl;
		for (i = 0; i < num; i++){
			cout << "[" << beads[i][0] << ", " << beads[i][2] << "] ";
		}
		cout << endl << endl;
		for (i = 0; (i < 27) && s; i++){
			if (alphabet[i] % 2) { s = !s; }
		}
		if (s){
			cout << "It's Possible to make complete Bracelet as follows!!" << endl;
			while (1){
				for (i = 1; i < num; i++){
					if (beads[0][0] == beads[i][2]){
						strcpy_s(tmp, 4, beads[i]);
						strcpy_s(beads[i], 4, beads[num - 1]);
						strcpy_s(beads[num - 1], 4, tmp);
						break;
					}
					else if (beads[0][0] == beads[i][0]){
						tmp[0] = beads[i][0];
						beads[i][0] = beads[i][2];
						beads[i][2] = tmp[0];
						strcpy_s(tmp, 4, beads[i]);
						strcpy_s(beads[i], 4, beads[num - 1]);
						strcpy_s(beads[num - 1], 4, tmp);
						break;
					}
				}
				for (i = 0; i < num - 2; i++){
					for (j = i + 1; j < num - 1; j++){
						if (beads[i][2] == beads[j][0]){
							strcpy_s(tmp, 4, beads[i + 1]);
							strcpy_s(beads[i + 1], 4, beads[j]);
							strcpy_s(beads[j], 4, tmp);
						}
						else if (beads[i][2] == beads[j][2]){
							tmp[0] = beads[j][0];
							beads[j][0] = beads[j][2];
							beads[j][2] = tmp[0];
							strcpy_s(tmp, 4, beads[i + 1]);
							strcpy_s(beads[i + 1], 4, beads[j]);
							strcpy_s(beads[j], 4, tmp);
						}
					}
				}
				if ((beads[i + 1][2] == beads[0][0]) && (beads[i + 1][0] == beads[i][2]))
					break;
			}
			for (i = 0; i < num; i++){
				cout << "[" << beads[i][0] << ", " << beads[i][2] << "]";
				if (i < num - 1) { cout << "-"; }
			}
			cout << endl << endl;
		}
		else
			cout << "It's IMPOSSIBLE to make complete Bracelet!!" << endl << endl;
		while (1){
			cout << "One MORE?? ;-)  :  ";
			cin >> yn;
			if (yn == 'y' || yn == 'Y'){
				cout << "\n=======================================================\n\n";
				break;
			}
			else if (yn == 'n' || yn == 'N')
				exit(1);
			else
				cout << "y/n ONLY!" << endl;
		}
	}
	return 0;
}
