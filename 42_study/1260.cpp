#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <vector>
#include <queue>
#include <algorithm>

int N, M, V;
vector<int> graph[1001];
int visited[1001];

void init_visited()
{
    for(int i = 1; i<=1001; i++)
        visited[i] = 0;
}

void dfs(int node)
{
    visited[node] = 1;
    cout << node << " ";
    for(int i = 0; i < graph[node].size(); i++)
    {
        if (visited[graph[node][i]] == 0)
            dfs(graph[node][i]);
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visited[cur] == 0)
        {
            visited[cur] = 1;
            cout << cur << " ";
        }

        for(int i = 0; i<graph[cur].size(); i++)
        {
            if (visited[graph[cur][i]] == 0)
                q.push(graph[cur][i]);
        }
    }
}

int main(void)
{
    fast_io;

    cin >> N >> M >> V;
    for(int i = 0; i<M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i<=N; i++)
		sort(graph[i].begin(), graph[i].end());
    dfs(V);
    cout << endl;
    init_visited();
    bfs(V);
}