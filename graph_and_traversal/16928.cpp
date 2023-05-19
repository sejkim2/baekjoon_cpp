#include <iostream>
#include <queue>
#define endl '\n';
using namespace std;

int N, M, x, y, u, v;
int Map[101];
int visited[101];
queue<int> q;

void bfs()
{
	q.push(1);
	while (!q.empty())
	{
		int cordi = q.front();
		q.pop();
		for(int i = 1; i<=6; i++)
		{
			int move_cordi = cordi + i;
			if (move_cordi < 1 || move_cordi > 100 || visited[move_cordi] > 0)
				continue;
			if (Map[move_cordi] > 0)
				move_cordi = Map[move_cordi];
			if (visited[move_cordi] == 0)
			{
				visited[move_cordi] = visited[cordi] + 1;
				q.push(move_cordi);
			}		
		}
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i<N; i++)
	{
		cin >> x >> y;
		Map[x] = y;
	}
	for(int i = 0; i<M; i++)
	{
		cin >> u >> v;
		Map[u] = v;
	}
	bfs();
	cout << visited[100];
}
