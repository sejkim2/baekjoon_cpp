#include <iostream>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, I, cur_x, cur_y, expect_x, expect_y;
int move_row[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int move_col[8] = {-1, 1, 2, -2, 2, -2, 1, -1};

int bfs(int row, int col)
{
	queue<pair<int, int> > q;
	int visited[301][301];
	for(int i = 0; i<301; i++)
	{
		for(int j = 0; j<301; j++)
			visited[i][j] = 0;
	}
	visited[row][col] = 1;
	
	q.push(make_pair(row, col));
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (r == expect_x && c == expect_y)
			return visited[r][c];
		for(int i = 0; i<8; i++)
		{
			int x = r + move_row[i];
			int y = c + move_col[i];
			if (x < 0 || y < 0 || x >= I || y >= I)
				continue;
			if (visited[x][y] == 0)
			{
				visited[x][y] = visited[r][c] + 1;
				q.push(make_pair(x, y));
			}
		}
	}
	return (visited[expect_x][expect_y]);
}

int main()
{
	cin >> n;

	for(int i = 0; i<n; i++)
	{
		cin >> I;
		cin >> cur_x >> cur_y;
		cin >> expect_x >> expect_y;
		cout << bfs(cur_x, cur_y) - 1 << endl;
	}
}
