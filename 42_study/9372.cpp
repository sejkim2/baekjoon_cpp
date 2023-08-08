#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <vector>
#include <algorithm>

int T, N, M, a, b;
int ans;
int parent[1001];


void init_parent()
{
    for(int i = 1; i<=1000; i++)
        parent[i] = i;
}

int find_parent(int vertex)
{
    if (parent[vertex] == vertex)
        return (vertex);
    else
        return (find_parent(parent[vertex]));
}

void Union(int v1, int v2)
{
    int v1_parent = find_parent(v1);
    int v2_parent = find_parent(v2);
    if (v1_parent != v2_parent)
    {
        int p = min(v1_parent, v2_parent);
        int c = max(v1_parent, v2_parent);
        parent[c] = p;
    }
}

int main(void)
{
    fast_io;

    cin >> T;
    while (T--)
    {
        vector<pair<int, int> > graph;
        cin >> N >> M;
        ans = 0;
        init_parent();

        for(int i = 1; i<=M; i++)
        {
            cin >> a >> b;
            graph.push_back(make_pair(a, b));
        }
        sort(graph.begin(), graph.end());
        for(int i = 0; i<graph.size(); i++)
        {
            int v1 = graph[i].first;
            int v2 = graph[i].second;
            if (find_parent(v1) != find_parent(v2))
            {
                Union(v1, v2);
                ans++;
            }
        }
        cout << ans << endl;
    }
}