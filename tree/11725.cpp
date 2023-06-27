#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define endl '\n'
using namespace std;

#include <vector>

int n;
int parent[100001];
vector<int> tree[100001];

void dfs(int node)
{
	for(int i = 0; i<tree[node].size(); i++)
	{
		int next_node = tree[node][i];
		if (!parent[next_node])
		{
			parent[next_node] = node;
			dfs(next_node);
		}
	}
}

int main()
{
	cin >> n;

	for(int i = 1; i<n; i++)
	{
		int ver1, ver2;
		cin >> ver1 >> ver2;
		tree[ver1].push_back(ver2);
		tree[ver2].push_back(ver1);
	}

	dfs(1);
	for(int i = 2; i<=n; i++)
		cout << parent[i] << endl;
}