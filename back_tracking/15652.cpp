#include <iostream>
#define endl '\n';
using namespace std;

int n, m;
bool visited[9];
int ar[9];

void dfs(int count, int num)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
			cout << ar[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = num; i < n; i++)
		{
			visited[count] = true;
			ar[count] = i + 1;
			dfs(count + 1, i);
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
	dfs(0, 0);
}