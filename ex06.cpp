#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
#define endl '\n'

char	table[2001][2001] = {0, };
int sum[2001][2001] = {0, };
int n, m, k;
int result;

int count(char color)
{
	//int sum[n+1][m+1] = {0, };
	result = INT_MAX;
	for(int i = 1; i<= n; i++)
	{
		for(int j = 1; j<= m; j++)
		{
			int tmp;
			if ((i + j) % 2 == 0) tmp = (table[i][j] != color);
			else tmp = (table[i][j] == color);
			sum[i][j] = sum[i][j-1] + sum[i-1][j] + tmp - sum[i-1][j-1];
		}
	}

	for(int i = 1; i<= n - k + 1; i++)
	{
		for(int j = 1; j<= m - k + 1; j++)
			result = min(result, sum[i + k - 1][j + k - 1] + sum[i - 1][j - 1] - sum[i + k - 1][j - 1] - sum[i  - 1][j + k - 1]);
	}
	return (result);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i<= n; i++)
	{
		for(int j = 1; j<= m; j++)
			cin >> table[i][j];
	}

	cout << min(count('B'), count('W'));	
}
