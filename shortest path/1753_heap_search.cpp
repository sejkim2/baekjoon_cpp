#include <iostream>
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

#define INF 9999999
int V, E, K, u, v, w;
priority_queue<pair<int, int> > pq;
vector<pair<int, int> > graph[20001];
int Distance[20001];

void dijkstra(int Start) 
{
	for(int i = 1; i<=V; i++)
		Distance[i] = INF;
		
	pq.push(make_pair(0, Start));
	Distance[Start] = 0;
	
	while (!pq.empty())
	{
		int weight = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for(int i = 0; i<graph[cur].size(); i++)
		{
			int search_node = graph[cur][i].first;
			if (Distance[search_node] > weight + graph[cur][i].second)
			{
				Distance[search_node] = weight + graph[cur][i].second;
				pq.push(make_pair(-Distance[search_node], search_node));
			}
		}
	}
}

int main()
{
	cin >> V >> E;
	cin >> K;

	for(int i = 0 ; i<E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
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
