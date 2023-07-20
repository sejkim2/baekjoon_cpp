#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'
using namespace std;

#include <queue>
#include <vector>
#include <algorithm>

queue<pair<int, int> > q;
vector<pair<int, int> > v[101];
vector<pair<int, int> > graph[101];
int N;
int dp[101];
int inEdge[101];

int main()
{
	cin >> N;
	for(int i = 1; i<=N; i++)
	{
		int tier, time;
		cin >> tier >> time;
		v[tier].push_back(make_pair(i, time));
	}

	for(int i = 1; i<=N-1; i++)
	{
		for(int j = 0; j<v[i].size(); j++)
		{
			int cur_node = v[i][j].first;
			int cur_time = v[i][j].second;
			for(int k = 0; k<v[i+1].size(); k++)
			{
				int next_node = v[i+1][k].first;
				int next_time = v[i+1][k].second;
				graph[cur_node].push_back(make_pair(next_node, next_time));
				inEdge[next_node]++;
			}
		}
	}

	for(int i = 0; i < v[0].size(); i++)
		q.push(make_pair(v[0][i].first, v[0][i].second));
	
	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		for(int i = 0; i<graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			int next_time = graph[cur_node][i].second;
			int cost = cur_time + pow(cur_node - next_node, 2) + next_time;
			
			dp[next_node] = max(dp[next_node], cost);
			inEdge[next_node]--;
			if (inEdge[next_node] == 0)
				q.push(make_pair(next_node, dp[next_node]));
		}
	}
}