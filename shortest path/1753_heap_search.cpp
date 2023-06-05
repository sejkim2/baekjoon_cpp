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
		
	pq.push(make_pair(0, Start)); // pair의 첫번째 원소부터 정렬의 기준이 되기 때문에 가중치가 first가 된다.
	Distance[Start] = 0;
	
	while (!pq.empty())
	{
		int weight = -pq.top().first;	//stl의 heap은 default가 최대 힙이기 때문에 루트에는 항상 최댓값이 놓인다.
		// 음수를 곱해서 큰 수일 수록 힙의 아래로 가게 만든다 (최소 힙처럼 사용하여 최소값이 루트로 가게 만든다.)
		int cur = pq.top().second;
		pq.pop();

		for(int i = 0; i<graph[cur].size(); i++)	//우선순위 큐를 사용하여 벡터의 원소만큼만 순회하므로 visited가 필요 없음(각 노드별로 중복 탐색을 하지 않음)
		{
			int search_node = graph[cur][i].first;
			if (Distance[search_node] > weight + graph[cur][i].second)	//distance : 원래 직접 가는 거리
			//weight + 해당 노드에서 목적지 노드까지 거리(경유 거리)
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
