#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int m, n, ans;
int move_row[4] = {1, -1, 0, 0};
int move_col[4] = {0, 0, 1, -1};
vector<vector<int> > box;
vector<vector<int> > vistied;
queue<pair<int, int> > q;

void bfs()
{
	// vistied[q.front().first][q.front().second] = 1;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++)
		{
			int x = r + move_row[i];
			int y = c + move_col[i];
			if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || box[x][y] != 0)
				continue;
			if (vistied[x][y] == 0)
			{
				q.push(make_pair(x, y));
				vistied[x][y] = vistied[r][c] + 1;
			}
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
		vistied[i].resize(m + 1);
		for(int j = 0; j<m; j++)
		{
			int tomato;
			cin >> tomato;
			box[i].push_back(tomato);
			if (tomato == 1)
				q.push(make_pair(i, j));	//같은 날에 서로 다른 곳에서 토마토가 익을 수수
			//있으므로 큐에 넣어서 순서를 준다.
			// vistied[i][j] = 0;
		}
	}
	bfs();
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if (vistied[i][j] == 0 && box[i][j] == 0)
			{
				ans = -1;
				break;
			}	
			else 
				ans = max(ans, vistied[i][j]);
		}
		if (ans == -1)
			break;
	}
	cout << ans;
}
