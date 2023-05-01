#include <iostream>
#define endl '\n';
#define MAX 14;
#include <cmath>
using namespace std;

int n;
int cnt = 0;
int table[14] = { 0, };

bool isPass(int numOfRow)
{
	for (int i = 0; i < numOfRow; i++)
	{
		if (table[i] == table[numOfRow] || abs(table[i] - table[numOfRow]) == numOfRow - i)
			return false;
	}

	return true;
}

void placeQueen(int numOfRow)
{
	if (numOfRow == n)
		cnt++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			table[numOfRow] = i;
			if (isPass(numOfRow))
				placeQueen(numOfRow + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	placeQueen(0);

	cout << cnt;
}