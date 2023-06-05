#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

#define INF 9999999
int T;
int n, m, t;
int s, g, h;
int a, b, d;
int x;
vector<pair<int, int> > graph[2001];	//first : node, second : weight
vector<int> target_possible;
int Distance_s[2001];
int Distance_g[2001];
int Distance_h[2001];

void init_graph()
{
	for(int i = 1; i<=2000; i++)
		graph[i].clear();
}

void init_distance()
{
	for(int i = 1; i<=n; i++)
	{
		Distance_s[i] = INF;
		Distance_g[i] = INF;
		Distance_h[i] = INF;
	}
}

void dijkstra(int Start, int Distance[2001])
{
	priority_queue<pair<int, int> > pq;	//first : weight, second : node, default가 max heap이기 때문에 weight * -1
	
	pq.push(make_pair(0, Start));
	Distance[Start] = 0;

	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_weight = -pq.top().first;
		pq.pop();

		for(int i = 0; i<graph[cur_node].size(); i++)
		{
			int target_node = graph[cur_node][i].first;
			int target_weight = graph[cur_node][i].second;
			if (Distance[target_node] > Distance[cur_node] + target_weight)
			{
				Distance[target_node] = Distance[cur_node] + target_weight;
				pq.push(make_pair(-target_weight, target_node));
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		init_graph();
		target_possible.clear();
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		init_distance();
		for(int i = 0; i<m; i++)
		{
			cin >> a >> b >> d;
			graph[a].push_back(make_pair(b, d));
			graph[b].push_back(make_pair(a, d));
		}
		for(int i = 0; i<t; i++)
		{
			cin >> x;
			target_possible.push_back(x);
		}
		
		sort(target_possible.begin(), target_possible.end());

		dijkstra(s, Distance_s);
		dijkstra(g, Distance_g);
		dijkstra(h, Distance_h);

		for(int i = 0; i<t; i++)
		{
			int nd = target_possible[i];
			if (Distance_s[nd] == (Distance_s[g] + Distance_g[h] + Distance_h[nd]))
				cout << nd << " ";
			else if (Distance_s[nd] == (Distance_s[h] + Distance_h[g] + Distance_g[nd]))
				cout << nd << " ";
		}
		cout << endl;
	}
}