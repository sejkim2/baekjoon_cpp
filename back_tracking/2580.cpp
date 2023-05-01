#include <iostream>
#include <algorithm>
#define endl '\n';
using namespace std;

int table[9][9] = { 0, };
int flag = 0;

bool isPass(int row, int col, int num) {
	int start_row, start_col;

	for (int i = 0; i < 9; i++) {
		if (table[row][i] == num || table[i][col] == num) return false;
	}

	if (row < 3) start_row = 0;
	else if (row >= 3 && row < 6) start_row = 3;
	else start_row = 6;

	if (col < 3) start_col = 0;
	else if (col >= 3 && col < 6) start_col = 3;
	else start_col = 6;

	for (int i = start_row; i < start_row + 3; i++) {
		for (int j = start_col; j < start_col + 3; j++) {
			if (table[i][j] == num) return false;
		}
	}

	return true;
}

void makeTable(int row, int col) {
	if (row > 8) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << table[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}
	else if (col > 8)
		makeTable(row + 1, 0);

	else if (table[row][col] == 0){
		for (int i = 0; i < 9; i++) {
			if (isPass(row, col, i+1)) {
				table[row][col] = i + 1;
				makeTable(row, col + 1);
				table[row][col] = 0;
			}
		}
	}
	else makeTable(row, col + 1);
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) 
			cin >> table[i][j];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (table[i][j] == 0)
				makeTable(i, j);
		}
	}
}