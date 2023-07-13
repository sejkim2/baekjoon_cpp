#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <vector>
#include <stack>
int V, vertex;
int Visited[100001];
int Max_diameter, Max_vertex;
vector<pair<int, int> > Tree[100001];

void dfs(int vertex, int diameter)
{
	if (Max_diameter < diameter)
	{
		Max_diameter = diameter;
		Max_vertex = vertex;
	}
	for (int j = 0; j < Tree[vertex].size(); j++)
	{
		int adj_vertex = Tree[vertex][j].first;
		int sum_diameter = Tree[vertex][j].second + diameter;
		if (!Visited[adj_vertex])
		{
			Visited[adj_vertex] = 1;
			dfs(adj_vertex, sum_diameter);
		}
	}
}

int main()
{
	cin >> V;
	for(int i = 1; i<=V; i++)
	{
		cin >> vertex;
		int adj_vertex, adge;
		while (1)
		{
			cin >> adj_vertex;
			if (adj_vertex == -1)
				break;
			cin >> adge;
			Tree[adj_vertex].push_back(make_pair(vertex, adge));
		}
	}
	Max_diameter = -1;
	Visited[1] = 1;
	dfs(1, 0);
	for(int i = 1; i<=V; i++)
		Visited[i] = 0;
	Max_diameter = -1;
	Visited[Max_vertex] = 1;
	dfs(Max_vertex, 0);
	cout << Max_diameter;
}