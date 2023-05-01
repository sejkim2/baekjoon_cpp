#include <iostream>
#include <algorithm>
#define endl '\n';
using namespace std;

int main()
{
	int n;
	int ar[1001];
	int dp1[1001];
	int dp2[1001];
	int result = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		dp1[i] = 1;
		dp2[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (ar[i] > ar[j])
				dp1[i] = max(dp1[j] + 1, dp1[i]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (ar[n - i + 1] > ar[n - j + 1])
				dp2[n - i + 1] = max(dp2[n - j + 1] + 1, dp2[n - i + 1]);
		}
	}

	for (int i = 1; i <= n; i++)
		result = max(result, dp1[i] + dp2[i]);

	cout << result;
}