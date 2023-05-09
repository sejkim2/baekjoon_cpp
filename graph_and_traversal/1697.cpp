#include <iostream>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, k;
int visited[100001];
queue<int> q;

int bfs(int vertex)
{
	q.push(vertex);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == k)
			return visited[k];
		if (v + 1 >= 0 && v + 1 <= 100000 && visited[v + 1] == 0)
		{
			visited[v + 1] = visited[v] + 1;
			q.push(v + 1);
		}
		if (v - 1 >= 0 && v - 1 <= 100000 && visited[v - 1] == 0)
		{
			visited[v - 1] = visited[v] + 1;
			q.push(v - 1);	
		}
		if (v * 2 >= 0 && v * 2 <= 100000 && visited[v * 2] == 0)
		{
			visited[v * 2] = visited[v] + 1;
			q.push(v * 2);
		}
	}
	return (visited[k]);
}

int main()
{
	cin >> n >> k;
	int ans = bfs(n);
	cout << ans;
}
