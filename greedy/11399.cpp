#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int n, result;
int times[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	times[0] = 0;
	dp[0] = 0;
	for(int i = 1 ; i <= n; i++)
		cin >> times[i];
	sort(times + 1, times + n + 1);
	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i-1] + times[i];
		result += dp[i];
	}
	cout << result;
}
