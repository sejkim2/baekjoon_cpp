#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

int n, Minus, Zero, Plus;
int table[3000][3000];

bool isSame(int row, int col, int Size)
{
	int result = table[row][col];

	for(int i = row; i< row + Size; i++)
	{
		for(int j = col; j < col + Size; j++)
		{
			if (result != table[i][j])
				return false;
		}
	}
	return (true);
}

void div_conq(int row, int col, int Size)
{
	if (!isSame(row, col, Size))
	{
		for(int i = 0; i< 3; i++)
		{
			for(int j = 0; j< 3; j++)
				div_conq(row + (Size / 3) * i, col + (Size / 3) * j, Size / 3);
		}
		// div_conq(row, col, Size / 3);
		// div_conq(row, col + Size / 3, Size / 3);
		// div_conq(row, col + Size / 3 + Size / 3, Size / 3);
		// div_conq(row + Size / 3, col, Size / 3);
		// div_conq(row + Size / 3, col + Size / 3, Size / 3);
		// div_conq(row + Size / 3, col + Size / 3 + Size / 3, Size / 3);
		// div_conq(row + Size / 3 + Size / 3, col, Size / 3);
		// div_conq(row + Size / 3 + Size / 3, col + Size / 3, Size / 3);
		// div_conq(row + Size / 3 + Size / 3, col + Size / 3 + Size / 3, Size / 3);
	}
	else
	{
		if (table[row][col] == -1)
			Minus++;
		else if (table[row][col] == 0)
			Zero++;
		else
			Plus++;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
			cin >> table[i][j];
	}
	
	div_conq(1, 1, n);
	cout << Minus << endl << Zero << endl << Plus;
}
