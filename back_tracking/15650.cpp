#include <iostream>
#define endl '\n';
using namespace std;

int n, m;
int table[9];
bool visited[9];

void dfs(int count, int num)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
			cout << table[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = num; i < n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;	//node 방문
				table[count] = i + 1;
				dfs(count + 1, i + 1);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0, 0);
}