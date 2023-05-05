#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int t, m, n, k, x, y;
int num_of_Earthworm;
int move_row[4] = {0, -1, 0, 1};
int move_col[4] = {1, 0, -1, 0};
int cabbage_field[51][51];

void dfs(int row, int col)
{
	cabbage_field[row][col] = 0;
	for(int i = 0; i<4; i++)
	{
		int X = row + move_row[i];
		int Y = col + move_col[i];
		if (X < 0 || X > n - 1 || Y < 0 || Y > m - 1)
			continue;
		if (cabbage_field[X][Y] == 1)
			dfs(X, Y);
	}
}

void run_dfs()
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (cabbage_field[i][j] == 1)
			{
				num_of_Earthworm++;
				dfs(i, j);
			}
		}
	}
}

int main()
{
	cin >> t;
	for(int i = 0; i<t; i++)
	{
		cin >> m >> n >> k;
		for(int j = 0; j<k; j++)
		{
			cin >> x >> y;
			cabbage_field[y][x] = 1;
		}
		num_of_Earthworm = 0;
		run_dfs();
		cout << num_of_Earthworm << endl;
	}
}
