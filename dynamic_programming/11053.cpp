#include <iostream>
#include <algorithm>
#define endl '\n';
using namespace std;

int main()
{
	int n;
	int dp[1001];
	int ar[1001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (ar[i] > ar[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
}