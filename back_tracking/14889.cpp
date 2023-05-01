#include <iostream>
#include <cmath>	//abs()
#include <limits.h>
#include <algorithm>
#define endl '\n';
using namespace std;

int n;
int table[20][20];
bool team[21];
int MIN = INT_MAX;

void dfs(int count, int index)
{
	if (count == n / 2)
	{
		int start = 0;
		int link = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (team[i] == true && team[j] == true)
					start += table[i][j];
				if (team[i] == false && team[j] == false)
					link += table[i][j];
			}
		}

		MIN = min(MIN, abs(start - link));
		return;
	}
	else
	{
		for (int i = index; i < n; i++)
		{
			team[i] = true;
			dfs(count + 1, i + 1);
			team[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> table[i][j];
	}

	dfs(0, 0);

	cout << MIN;
}