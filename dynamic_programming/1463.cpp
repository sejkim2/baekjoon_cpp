#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n';
using namespace std;

int find_min(int n1, int n2, int n3)
{
	return min(min(n1, n2), n3);
}

int main()
{
	int n;
	vector<int> dp(1000001);
	//int dp[100];

	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 2 == 0)
				dp[i] = find_min(dp[i - 1], dp[i / 3], dp[i / 2]) + 1;
			else
				dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[n];
}