#include <iostream>
#include <algorithm>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, m, r, res = 1;
vector<vector<int> > graph;
vector<bool> vistied;
vector<int> result;

void dfs(int vertex)
{
    result[vertex] = res;
    res++;
    vistied[vertex] = true;
    for(int i = 0; i< graph[vertex].size(); i++)
    {
        int index = graph[vertex][i];
        if (!vistied[index])
            dfs(index);
    }
}

int main() 
{
    cin >> n >> m >> r;
    graph.resize(n + 1);
    vistied.resize(n + 1);
    result.resize(n + 1);

    for(int i = 0; i< m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        //connect the graph's vertex
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    //sort with each vertex
    for(int i = 1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());
    dfs(r);
    for(int i = 1; i<=n; i++)
        cout << result[i] << endl;
}