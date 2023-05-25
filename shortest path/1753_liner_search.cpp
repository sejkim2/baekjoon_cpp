#include <iostream>
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

#define INF 9999999
int V, E, K, u, v, w;
int graph[20001][20001];
int Distance[20001];
int Vistied[20001];

int find_min_weight()
{
	int Min = INF;
	int min_index = 1;
	for(int i = 1; i<=V; i++)
	{
		if (Vistied[i] == 0)
		{
			if (Distance[i] < Min)
			{
				Min = Distance[i];
				min_index = i;
			}
		}
	}
	return (min_index);
}

void dijkstra(int Start)
{
	Vistied[Start] = 1;
	
	for(int i = 1; i<=V; i++)
		Distance[i] = graph[Start][i];
	
	for(int i = 1; i<=V; i++)
	{
		int cur = find_min_weight();
		Vistied[cur] = 1;
		for(int j = 1; j<=V; j++)
		{
			if (Vistied[j] == 0)
			{
				if (Distance[j] > Distance[cur] + graph[cur][j])
					Distance[j] = Distance[cur] + graph[cur][j];
			}
		}
	}
}

int main()
{
	cin >> V >> E;
	cin >> K;

	for(int i = 1; i<=V; i++)
	{
		for(int j = 1; j<=V; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	for(int i = 0 ; i<E; i++)
	{
		cin >> u >> v >> w;
		graph[u][v] = w;
	}

	dijkstra(K);
	for(int i = 1; i<=V; i++)
	{
		if (Distance[i] == INF)
			cout << "INF" << endl;
		else
			cout << Distance[i] << endl;
	}
}
