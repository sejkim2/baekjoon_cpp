#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cout.tie(false), cin.tie(false)
#define endl '\n'
using namespace std;

#include <vector>

#define INF 9999999999
int N, M, A, B, C;
vector<pair<int, int> > city[501];
long long Distance[501];
bool ans;

void bellman_ford(int Start)
{
	for(int i = 1; i<=N; i++)
		Distance[i] = INF;
	Distance[Start] = 0;

	for(int i = 1; i <= N; i++)		//첫번째 노드부터 N-1 노드까지 매번 간선을 검사하며 N회 째에 갱신되는
	// 가중치가 있다면 음수 무한 순환 그래프 이므로 fail
	{
		for(int cur_node = 1; cur_node <= N; cur_node++)
		{
			for(int edge = 0; edge < city[cur_node].size(); edge++)
			{
				int next_node = city[cur_node][edge].first;
				int next_weight = city[cur_node][edge].second;
				if (Distance[cur_node] != INF && Distance[next_node] > Distance[cur_node] + next_weight)
				{
					Distance[next_node] = Distance[cur_node] + next_weight;
					if (i == N)
					{
						ans = false;
						return;
					}
				}
			}
		}
	}
}

int main()
{
	ans = true;
	cin >> N >> M;
	for(int i = 0; i<M; i++)
	{
		cin >> A >> B >> C;
		city[A].push_back(make_pair(B, C));
	}

	bellman_ford(1);
	if (ans == true)
	{
		for(int i = 2; i<=N; i++)
		{
			if (Distance[i] == INF)
				cout << "-1" << endl;
			else cout << Distance[i] << endl;
		}
	}
	else
		cout << "-1" << endl;
}