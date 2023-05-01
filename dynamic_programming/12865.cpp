#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n';
using namespace std;

int main()
{
	int n;
	int k;
	int dp[101][100001] = { 0, };
	vector<pair<int, int> > v;

	cin >> n >> k;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= n; i++)
	{
		int weight, value;
		cin >> weight >> value;

		v.push_back(make_pair(weight, value));
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j < v[i].first)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
		}
	}

	cout << dp[n][k];
}