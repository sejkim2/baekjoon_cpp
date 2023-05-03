#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, m, v;
vector<vector<int> > graph;
queue<int> q;
bool vistied_dfs[1001];
bool vistied_bfs[1001];

void dfs(int vertex)
{
	if (!vistied_dfs[vertex])
	{	
		vistied_dfs[vertex] = true;
		cout << vertex << " ";
	}
	
	for(int i = 0; i<graph[vertex].size(); i++)
	{
		int v1 = graph[vertex][i];
		if (!vistied_dfs[v1])
			dfs(v1);
	}
}

void bfs(int vertex)
{
	vistied_bfs[vertex] = true;
	q.push(vertex);

	while (!q.empty())
	{
		int v1 = q.front();
		cout << v1 << " ";
		q.pop();
		for(int i = 0; i<graph[v1].size(); i++)
		{
			int v2 = graph[v1][i];
			if (!vistied_bfs[v2])
			{
				vistied_bfs[v2] = true;
				q.push(v2);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
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
	dfs(v);
	cout << endl;
	bfs(v);
}
