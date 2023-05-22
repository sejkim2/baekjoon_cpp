#include <iostream>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int N, M, ans;
int Map[1002][1002];
int visited[1002][1002][2];
int move_row[4] = {1, -1, 0, 0};
int move_col[4] = {0, 0, 1, -1};
queue<pair<pair<int, int>, int > > q;

int bfs()
{
	q.push(make_pair(make_pair(1, 1), 0));
	visited[1][1][0] = 1;
	while (!q.empty())
	{
		int r = q.front().first.first;
		int c = q.front().first.second;
		int flag = q.front().second;
		q.pop();
		if (r == N && c == M)
		{
			return (visited[r][c][flag]);
		}
		for(int i = 0; i<4; i++)
		{
			int x = r + move_row[i];
			int y = c + move_col[i];
			if (x > N || x < 1 || y > M || y < 1)
				continue;
			if (Map[x][y] == 1 && flag == 0)
			{
				q.push(make_pair(make_pair(x, y), 1));
				visited[x][y][1] = visited[r][c][0] + 1;
			}
			else if (Map[x][y] == 0 && visited[x][y][flag] == 0)
			{
				q.push(make_pair(make_pair(x, y), flag));
				visited[x][y][flag] = visited[r][c][flag] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j<=M; j++)
			scanf("%1d", &Map[i][j]);
	}

	ans = bfs();
	cout << ans;
}
