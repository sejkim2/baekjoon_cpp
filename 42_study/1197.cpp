#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>
#include <queue>

int ans;
int V, E, A, B, C;
int parent[10001];
priority_queue<pair<int, pair<int, int> > > pq;

int find_parent(int v)
{
    if (parent[v] == v)
        return (v);
    else
        return (find_parent(parent[v]));
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

bool is_cycle(int v1, int v2)
{
    int v1_parent = find_parent(v1);
    int v2_parent = find_parent(v2);
    if (v1_parent == v2_parent)
        return (true);
    else
        return (false);
}

void init_parent()
{
    for(int i = 1; i<=V; i++)
        parent[i] = i;
}

int main(void)
{
    fast_io;

    cin >> V >> E;
    init_parent();

    for(int i = 1; i<=E; i++)
    {
        cin >> A >> B >> C;
        pq.push(make_pair(-C, make_pair(A, B)));
    }

    while (!pq.empty())
    {
        int weight = -1 * (pq.top().first);
        int v1 = pq.top().second.first;
        int v2 = pq.top().second.second;
        pq.pop();
        if (is_cycle(v1, v2) == false)
        {
            Union(v1, v2);
            ans += weight;
        }
    }
    cout << ans;
}