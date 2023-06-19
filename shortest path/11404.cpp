#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'
using namespace std;

#include <vector>
#include <queue>
#define INF 99999999

int n, m, a, b, c;
vector<pair<int, int> > v[101];	//first : node, second : cost
int Distance[101];

void init_distance()
{
	for(int i = 1; i<=n; i++)
		Distance[i] = INF;
}

void dijkstra(int Start)
{
	//default : max heap
	//first : -cost(make min heap)
	//second : node number
	init_distance();
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, Start));
	Distance[Start] = 0;
	
	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for(int i = 0; i<v[cur_node].size(); i++)
		{
			int next_node = v[cur_node][i].first;
			int next_cost = v[cur_node][i].second;
			if (Distance[next_node] > next_cost + Distance[cur_node])
			{
				Distance[next_node] = next_cost + Distance[cur_node];
				pq.push(make_pair(-next_cost, next_node));
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	for(int i = 1; i<=m; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	for(int i = 1; i<=n; i++)
	{
		dijkstra(i);
		for(int j = 1; j<=n; j++)
		{
			if (Distance[j] == INF)
				cout << "0" << " ";
			else 
				cout << Distance[j] << " ";
		}
		cout << endl;
	}
}