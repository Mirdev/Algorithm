// This program checks if selected beads can form a closed bracelet and rearranges them accordingly.
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    int alphabet[26] = {0}, num, i, j;
    char beads[100][4] = {0}, tmp[4] = {0}, yn = 'y';
    
    while (1) {
        for (i = 0; i < 26; i++) alphabet[i] = 0;
        bool s = true;

        cout << "Insert the number of bead you're gonna choose (5~100): ";
        cin >> num;
        cin.ignore();

        if (num < 5 || num > 100) {
            cout << "Invalid input range! Try again.\n";
            continue;
        }

        cout << "Insert two colors of each bead (" << num << " total):" << endl;
        for (i = 0; i < num; i++) {
            cout << "=> " << i + 1 << ". : ";
            cin.getline(beads[i], 4);
            beads[i][0] = tolower(beads[i][0]);
            beads[i][2] = tolower(beads[i][2]);

            if (!((beads[i][0] >= 'a' && beads[i][0] <= 'z') && (beads[i][2] >= 'a' && beads[i][2] <= 'z'))) {
                cout << "Colors must be letters a~z. Re-enter please.\n";
                i--; continue;
            }

            alphabet[beads[i][0] - 'a']++;
            alphabet[beads[i][2] - 'a']++;
        }

        cout << "\nThis is YOUR BEADS you picked:\n";
        for (i = 0; i < num; i++) {
            cout << "[" << beads[i][0] << ", " << beads[i][2] << "] ";
        }
        cout << "\n\n";

        for (i = 0; i < 26 && s; i++) {
            if (alphabet[i] % 2 != 0) s = false;
        }

        if (s) {
            cout << "It's Possible to make complete Bracelet as follows!!\n";

            while (true) {
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

                if (beads[num - 1][2] == beads[0][0]) break;
            }

            for (i = 0; i < num; i++) {
                cout << "[" << beads[i][0] << ", " << beads[i][2] << "]";
                if (i < num - 1) cout << "-";
            }
            cout << "\n\n";
        } else {
            cout << "It's IMPOSSIBLE to make complete Bracelet!!\n\n";
        }

        while (true) {
            cout << "One MORE?? ;-)  (y/n): ";
            cin >> yn;
            cin.ignore();
            if (yn == 'y' || yn == 'Y') {
                cout << "\n================== New Run ==================\n\n";
                break;
            } else if (yn == 'n' || yn == 'N') {
                cout << "Bye~\n";
                return 0;
            } else {
                cout << "y/n ONLY!\n";
            }
        }
    }
}
