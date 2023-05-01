#include <iostream>
#define endl '\n';
using namespace std;

int n, m;
bool visited[8];
int ar[8];

void dfs(int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
			cout << ar[i] << " ";
		cout << endl;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			visited[count] = true;
			ar[count] = i + 1;
			dfs(count + 1);
			visited[count] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0);
}