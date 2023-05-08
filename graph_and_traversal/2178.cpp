#include <iostream>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, m;
int Map[102][102];
int visited[102][102];
int Move_row[4] = {1, 0, -1, 0};
int Move_col[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;

void bfs(int row, int col)
{
	Map[row][col] = 0;
	q.push(make_pair(row, col));
	visited[row][col] = 1;

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++)
		{
			int x = r + Move_row[i];
			int y = c + Move_col[i];
			if (x < 1 || y < 1 || x > n || y > m || Map[x][y] == 0)
				continue;
			if (Map[x][y] == 1)
			{
				q.push(make_pair(x, y));
				Map[x][y] = 0;
				visited[x][y] = visited[r][c] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
			scanf("%1d", &Map[i][j]);
	}

	bfs(1, 1);
	cout << visited[n][m];
}
