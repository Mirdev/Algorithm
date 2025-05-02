// This program checks if two input sentences are anagrams of each other
#include <ctype.h>
#include <iostream>
using namespace std;

int main(){
	int alphabet[2][26] = {0};
	char buf[256], ord[2][4] = {"1st", "2nd"};
	char m = 'y';

	while (m == 'y' || m == 'Y') {
		// Reset alphabet count arrays
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < 26; k++) alphabet[i][k] = 0;

			cout << "Input the " << ord[i] << " sentence: ";
			cin.getline(buf, 256);

			for (int j = 0; buf[j] != '\0'; j++) {
				if (isalpha(buf[j])) {
					alphabet[i][tolower(buf[j]) - 'a']++;
				}
			}
		}

		bool f = true;
		for (int i = 0; i < 26; i++) {
			if (alphabet[0][i] != alphabet[1][i]) {
				f = false;
				break;
			}
		}

		if (f)
			cout << "Yes! They are anagrams!!" << endl;
		else
			cout << "No! They are not anagrams!!" << endl;

		cout << "Continue? (y/N): ";
		cin >> m;
		cin.ignore();  // Ignore leftover newline
	}

	cout << "Thank you!!" << endl;
	return 0;
}// This program checks if two input sentences are anagrams of each other
#include <ctype.h>
#include <iostream>
using namespace std;

int main(){
	int alphabet[2][26] = {0};
	char buf[256], ord[2][4] = {"1st", "2nd"};
	char m = 'y';

	while (m == 'y' || m == 'Y') {
		// Reset alphabet count arrays
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < 26; k++) alphabet[i][k] = 0;

			cout << "Input the " << ord[i] << " sentence: ";
			cin.getline(buf, 256);

			for (int j = 0; buf[j] != '\0'; j++) {
				if (isalpha(buf[j])) {
					alphabet[i][tolower(buf[j]) - 'a']++;
				}
			}
		}

		bool f = true;
		for (int i = 0; i < 26; i++) {
			if (alphabet[0][i] != alphabet[1][i]) {
				f = false;
				break;
			}
		}

		if (f)
			cout << "Yes! They are anagrams!!" << endl;
		else
			cout << "No! They are not anagrams!!" << endl;

		cout << "Continue? (y/N): ";
		cin >> m;
		cin.ignore();  // Ignore leftover newline
	}

	cout << "Thank you!!" << endl;
	return 0;
}
