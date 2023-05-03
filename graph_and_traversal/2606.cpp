#include <iostream>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, connect_pair, infested;
vector<vector<int> > graph;
bool vistied[101];

void dfs(int vertex)
{
	if (!vistied[vertex])
	{
		vistied[vertex] = true;
		infested++;
	}
	for(int i = 0; i<graph[vertex].size(); i++)
	{
		int v = graph[vertex][i];
		if (!vistied[v])
			dfs(v);
	}
}

int main()
{
	cin >> n;				//num of vertex
	cin >> connect_pair;	//num of edge
	graph.resize(n + 1);
	for(int i = 0; i<connect_pair; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
	cout << infested - 1;
}
