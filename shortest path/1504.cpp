#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

#define INF 9999999
int N, E, a, b, c, v1, v2, u, v;
int flag, ans;
int s_to_v1, s_to_v2, v1_to_v2, v1_to_n, v2_to_n;
vector<pair<int, int> > graph[801]; //first : vertex b, second : weight c
int Distance[801];

void Dijkstra(int Start)
{
	priority_queue<pair<int, int> > pq;	//first : -weight, second : vertex, because default is Max heap, and sort standard is first
	//start vertex is 1
	pq.push(make_pair(0, Start));
	Distance[Start] = 0;
	while (!pq.empty())
	{
		int cur_weight = -pq.top().first;	//min heap으로 만들기 위해 heap에 넣을 때 음수 처리
		int cur_vertex = pq.top().second;
		pq.pop();

		for(int i = 0; i<graph[cur_vertex].size(); i++)
		{
			int next_vertex = graph[cur_vertex][i].first;
			int next_weight = graph[cur_vertex][i].second;	//cur -> next 까지의 weight
			if (Distance[next_vertex] >	cur_weight + next_weight)
			{
				Distance[next_vertex] = cur_weight + next_weight;
				pq.push(make_pair(-Distance[next_vertex], next_vertex));
			}
		}
	}
}

int main()
{
	cin >> N >> E;
	for(int i = 0; i<E; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	for(int i = 1; i <= N; i++)
		Distance[i] = INF;
	Dijkstra(1);	//1에서 N까지 최단 거리
	s_to_v1 = Distance[v1];	//start에서 v1까지의 최단 거리
	s_to_v2 = Distance[v2];	//start에서 v2까지의 최단 거리
    if (s_to_v1 == INF || s_to_v2 == INF)
        flag = 1;

	for(int i = 1; i <= N; i++)
		Distance[i] = INF;
	Dijkstra(v1);	//v1(v2)에서 N까지 최단 거리(양방향이므로 하나만 고려 가능)
	v1_to_v2 = Distance[v2]; //v1 에서 v2까지의 최단 거리 (Distance[v2]와 같다)
	v1_to_n = Distance[N];	//v1에서 n까지의 최단 거리
    if (v1_to_v2 == INF || v1_to_n == INF)
        flag = 1;

	for(int i = 1; i <= N; i++)
		Distance[i] = INF;
	Dijkstra(v2);	//v2에서 N까지 최단 거리
	v2_to_n = Distance[N];	//v2에서 n까지의 최단 거리
    if (v2_to_n == INF)
        flag = 1;

    if (flag == 1)
        ans = INF;
	else
        ans = min(s_to_v1 + v1_to_v2 + v2_to_n, s_to_v2 + v1_to_v2 + v1_to_n);

	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
}
