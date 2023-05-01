#include <iostream>
#define endl '\n';
using namespace std;

int n, m;
int table[9];
bool visit[9];

void dfs(int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
			cout << table[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				table[count] = i + 1;
				visit[i] = true;
				dfs(count + 1);
				visit[i] = false;
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
	dfs(0);
}