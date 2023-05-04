#include <iostream>
#include <algorithm>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, house_cnt;
vector<int> cnt;
int table[26][26];
int move_row[4] = {-1, 0, 1, 0};
int move_col[4] = {0, 1, 0, -1};

void dfs(int row, int col)
{
	table[row][col] = 0;
	house_cnt++;
	for(int i = 0; i<4; i++)
	{
		if (row + move_row[i] == 0 || row + move_row[i] == n + 1 || col + move_col[i] == 0 || col + move_col[i] == n + 1)
			continue;;
		if (table[row + move_row[i]][col + move_col[i]] == 1)
			dfs(row + move_row[i], col + move_col[i]);
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
			scanf("%1d", &table[i][j]);
			// cin >> table[i][j];
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if (table[i][j] == 1)
			{
				house_cnt = 0;
				dfs(i, j);
				cnt.push_back(house_cnt);
			}
		}
	}

	sort(cnt.begin(), cnt.end());

	cout << cnt.size() << endl;
	for(int i = 0; i<cnt.size(); i++)
		cout << cnt[i] << endl;
}
