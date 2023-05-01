#include <iostream>
#include <vector>
#define endl '\n';
using namespace std;

int ar[100001];
int dp[100001];

int main()
{
	int n, max;
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> ar[i];

	max = ar[0];
	dp[0] = ar[0];

	for (int i = 1; i < n; i++) {
		if ((dp[i - 1] + ar[i]) < ar[i])
			dp[i] = ar[i];
		else dp[i] = dp[i - 1] + ar[i];
		
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;
}