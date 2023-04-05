#include <iostream>
using namespace std;
#define endl '\n'

int n;
int table[129][129];
int white, blue;

bool is_same_color(int row, int col, int depth)
{
	int color = table[row][col];

	for(int i = row; i< row + n / depth; i++)
	{
		for(int j = col; j < col + n / depth; j++)
		{
			if (color != table[i][j])
				return false;
		}
	}
	return (true);
}

void div_conq(int row, int col, int depth)
{
	if (!is_same_color(row, col, depth))
	{
		div_conq(row, col, depth*2);
		div_conq(row, col + n / (depth*2), depth*2);
		div_conq(row + n / (depth*2), col, depth*2);
		div_conq(row + n / (depth*2), col + n / (depth*2), depth*2);
	}
	else
	{
		if (table[row][col] == 1)
			blue++;
		else
			white++;
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
	
	div_conq(1, 1, 1);
	cout << white << endl << blue;
}
