#include <iostream>
using namespace std;
#define endl '\n'

int n, m, k;
int a[101][101];
int b[101][101];
int result[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
			cin >> a[i][j];
	}
	cin >> m >> k;
	for(int i = 1; i<=m; i++)
	{
		for(int j = 1; j<=k; j++)
			cin >> b[i][j];
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j<= k; j++)
		{
			for(int t = 1; t <= m; t++)
				result[i][j] += (a[i][t] * b[t][j]);
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j<= k; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
