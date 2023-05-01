#include <iostream>
#include <algorithm>
#define endl '\n';
using namespace std;

int find_max(int n1, int n2, int n3)
{
	return max(max(n1, n2), n3);
}

int main()
{
	int n;
	int dp[10001];
	int juice[10001];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> juice[i];

	dp[1] = juice[1];
	dp[2] = dp[1] + juice[2];
	dp[3] = find_max(dp[2], juice[1] + juice[3], juice[2] + juice[3]);

	for (int i = 4; i <= n; i++)
		dp[i] = find_max(dp[i - 3] + juice[i - 1] + juice[i], dp[i - 2] + juice[i], dp[i - 1]);

	cout << dp[n];
}