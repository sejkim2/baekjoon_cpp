#include <iostream>
using namespace std;
#define endl '\n'

int n, b;
size_t tmp[6][6];
size_t a[6][6];
size_t res[6][6];

void div_conq_odd()
{
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<= n; j++)
		{
			tmp[i][j] = 0;
			for(int k = 1; k <= n; k++)
				tmp[i][j] += (res[i][k] * a[k][j]);
			tmp[i][j] %= 1000;
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j <= n; j++)
			res[i][j] = tmp[i][j];
	}
}

void div_conq_even()
{
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<= n; j++)
		{
			tmp[i][j] = 0;
			for(int k = 1; k <= n; k++)
				tmp[i][j] += (a[i][k] * a[k][j]);
			tmp[i][j] %= 1000;
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j <= n; j++)
			res[i][j] = tmp[i][j];
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	cin >> n >> b;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j<= n; j++)
		{
			cin >> a[i][j];
			res[i][j] = 1;
		}
	}
	while (b > 0)
	{
		if (b % 2 == 1)
			div_conq_odd();
		div_conq_even();
		b /= 2;	
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j<= n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}
