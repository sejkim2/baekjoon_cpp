#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <set>

int n, m, a, b, cmd;
int parent[1000001];

int findParent(int child_node)
{
    if (parent[child_node] == child_node)
        return (child_node);
    else
    {
        parent[child_node] = findParent(parent[child_node]);
        return parent[child_node];
    }
}

void unionParent(int a, int b)
{
    int a_parent = findParent(a);
    int b_parent = findParent(b);

    if (a_parent > b_parent)
        parent[a_parent] = b_parent;
    else
        parent[b_parent] = a_parent;
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(int i = 0; i<=n; i++)
        parent[i] = i;

    for(int i = 0; i<m; i++)
    {
        cin >> cmd >> a >> b;
        if (cmd == 0)
            unionParent(a, b);
        else
        {
            if (findParent(a) == findParent(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}