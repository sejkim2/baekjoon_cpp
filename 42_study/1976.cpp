#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>

int N, M;
int table[202][202];
int parent[202];
int travel[1001];

void init_parent()
{
    for(int i = 1; i<=N; i++)
        parent[i] = i;
}

int find_parent(int vertex)
{
    if (parent[vertex] == vertex)
        return (vertex);
    else
        return (parent[vertex] = find_parent(parent[vertex]));
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

    cin >> N >> M;
    init_parent();
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> table[i][j];
        for(int j = 1; j <= N; j++)
        {
            if (table[i][j] == 1)
            {
                if (find_parent(i) != find_parent(j))
                    Union(i, j);
            }
        }
    }
    for(int i = 1; i <= M; i++)
        cin >> travel[i];
    int p = parent[travel[1]];
    int flag = 0;
    for(int i = 1; i<=M; i++)
    {
        if (parent[travel[i]] != p)
        {
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    if (flag == 0)
        cout << "NO";
    else
        cout << "YES";
}