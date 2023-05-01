#include <iostream>
#define endl '\n';
using namespace std;

int main()
{
	int n;
	int mod;
	int count;
	int dp[101][10];

	mod = 1000000000;
	count = 0;
	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		count += dp[n][i];
		count %= mod;
	}

	cout << count;
}