#include <iostream>
#include <vector>
#include <string.h>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int K, V, E, u, v;
vector<int> graph[20001];
int visited[20001];		//not visited: 0, red : 1, blue : 2

void dfs(int node)
{
	for(int i = 0; i<graph[node].size(); i++)
	{
		int cur = graph[node][i];
		if (visited[cur] == 0)
		{
			if (visited[node] == 1)
				visited[cur] = 2;
			else if (visited[node] == 2)
				visited[cur] = 1;
			dfs(cur);
		}
	}
}

void run_dfs()
{
	for(int i = 1; i<=V; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i);
		}
	}
}

bool check_graph()
{
	for(int i = 1; i<=V; i++)
	{
		for(int j = 0; j<graph[i].size(); j++)
		{
			if (visited[i] == visited[graph[i][j]])
				return false;
		}
	}
	return true;
}

int main()
{
	cin >> K;
	for(int i = 0; i<K; i++)
	{
		cin >> V >> E;
		for(int j = 0; j<E; j++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		run_dfs();
		if (check_graph())
			cout << "YES" << endl;
		else cout << "NO" << endl;
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
	}
}
