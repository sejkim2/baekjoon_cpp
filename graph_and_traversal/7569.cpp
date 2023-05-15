#include <iostream>
#include <algorithm>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int m, n, h, ans;
int move_row[6] = {1, -1, 0, 0, 0, 0};
int move_col[6] = {0, 0, 1, -1, 0, 0};
int move_high[6] = {0, 0, 0, 0, 1, -1};
int box[103][103][103];
int vistied[103][103][103];
queue<pair<int, pair<int, int> > > q;

void bfs()
{
	while (!q.empty())
	{
		int hi = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		for(int i = 0; i<6; i++)
		{
			int z = hi + move_high[i];
			int x = r + move_row[i];
			int y = c + move_col[i];
			if (x < 0 || x > n - 1 || y < 0 || y > m - 1 
			|| z < 0 || z > h - 1 || box[z][x][y] != 0)
				continue;
			if (vistied[z][x][y] == 0)
			{
				q.push(make_pair(z, make_pair(x, y)));
				vistied[z][x][y] = vistied[hi][r][c] + 1;
			}
		}
	}
}

int main()
{
	cin >> m >> n >> h;
	for(int i = 0; i<h; i++)
	{
		for(int j = 0; j<n; j++)
		{
			for(int k = 0; k<m; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					q.push(make_pair(i, make_pair(j, k)));
			}
		}
	}

	bfs();

	for(int i = 0; i<h; i++)
	{
		for(int j = 0; j<n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if (vistied[i][j][k] == 0 && box[i][j][k] == 0)
				{
					ans = -1;
					break;
				}
				else
					ans = max(ans, vistied[i][j][k]);
			}
			if (ans == -1)
				break;
		}
		if (ans == -1)
			break;
	}
	cout << ans;
}
