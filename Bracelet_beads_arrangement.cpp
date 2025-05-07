// This program checks if selected beads can form a closed bracelet and rearranges them accordingly.
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    int alphabet[26] = {0}, num, i, j;
    char beads[100][4] = {0}, tmp[4] = {0};
    bool s = true;

    cout << "Insert the number of bead you're gonna choose (5~100): ";
    cin >> num;
    cin.ignore();

    if (num < 5 || num > 100) {
        cout << "Invalid number of beads!" << endl;
        return 1;
    }

    cout << "Insert two colors of each bead (total " << num << " beads):" << endl;
    for (i = 0; i < num; i++) {
        cout << i + 1 << ". : ";
        cin.getline(beads[i], 4);
        
        for (j = 0; j < 3; j += 2) {
            beads[i][j] = tolower(beads[i][j]);
            if (isalpha(beads[i][j])) {
                alphabet[beads[i][j] - 'a']++;
            }
        }
    }

    cout << "This is YOUR BEADS you picked:" << endl;
    for (i = 0; i < num; i++) {
        cout << "[" << beads[i][0] << ", " << beads[i][2] << "] ";
    }
    cout << endl;

    for (i = 0; i < 26 && s; i++) {
        if (alphabet[i] % 2 != 0) {
            s = false;
        }
    }

    if (s) {
        cout << "It's POSSIBLE to make complete Bracelet!!" << endl;

        for (i = 1; i < num; i++) {
            if (beads[0][0] == beads[i][2]) {
                strcpy(tmp, beads[i]);
                strcpy(beads[i], beads[num - 1]);
                strcpy(beads[num - 1], tmp);
                break;
            }
        }

        for (i = 0; i < num - 2; i++) {
            for (j = i + 1; j < num - 1; j++) {
                if (beads[i][2] == beads[j][0]) {
                    strcpy(tmp, beads[i + 1]);
                    strcpy(beads[i + 1], beads[j]);
                    strcpy(beads[j], tmp);
                    break;
                }
            }
        }

        cout << "Bracelet arrangement:" << endl;
        for (i = 0; i < num; i++) {
            cout << "[" << beads[i][0] << ", " << beads[i][2] << "] ";
        }
        cout << "[" << beads[num - 1][0] << ", " << beads[num - 1][2] << "] ";
        cout << endl;

    } else {
        cout << "It's IMPOSSIBLE to make complete Bracelet!!" << endl;
    }

    return 0;
}
