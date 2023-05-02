#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, m, r, res = 1;
vector<vector<int> > graph;
queue<int> q;
bool visited[100001];
int result[100001];

void bfs(int vertex)
{
	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		result[v] = res++;
		for(int i = 0; i<graph[v].size(); i++)
		{
			int v2 = graph[v][i];
			if (!visited[v2])
			{
				visited[v2] = true;
				q.push(v2);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> r;
	graph.resize(n + 1);
	for(int i = 0; i<m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i = 1; i<=n; i++)
		sort(graph[i].begin(), graph[i].end());
	bfs(r);
	for(int i = 1; i<=n; i++)
		cout << result[i] << endl;
}
