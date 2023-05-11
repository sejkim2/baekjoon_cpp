#include <iostream>
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int m, n, ans, num_of_ripe_tomato;
int move_row[4] = {1, -1, 0, 0};
int move_col[4] = {0, 0, 1, -1};
vector<vector<int> > box;
vector<vector<int> > vistied;
queue<pair<int, int> > q;

void bfs(int row, int col)
{
	q.push(make_pair(row, col));
	vistied[row][col] += 1;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (num_of_ripe_tomato == 0)
		{
			ans = vistied[r][c];
			return;
		}
		for(int i = 0; i<4; i++)
		{
			int x = r + move_row[i];
			int y = c + move_col[i];
			if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || vistied[x][y] != 0)
				continue;
			if (box[x][y] == 0)
			{
				q.push(make_pair(x, y));
				vistied[x][y] = vistied[r][c] + 1;
				num_of_ripe_tomato--;
			}
		}
	}
}

void run_bfs()
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if (box[i][j] == 1)
				bfs(i, j);
		}
	}
}

int main()
{
	cin >> m >> n;
	box.resize(n + 1);
	vistied.resize(n + 1);
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			int tomato;
			cin >> tomato;
			if (tomato == 0)
				num_of_ripe_tomato++;
			box[i].push_back(tomato);
		}
	}

	run_bfs();
	cout << ans;
}
