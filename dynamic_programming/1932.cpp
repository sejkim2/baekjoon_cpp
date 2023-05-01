#include <iostream>
#include <algorithm>
#define endl '\n';
using namespace std;

int ar[500][500];
int dp[500][500];

int main()
{
	int n, m = -1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> ar[i][j];
		}
	}

	dp[0][0] = ar[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + ar[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + ar[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + ar[i][j];
		}
	}

	for (int i = 0; i < n; i++) 
		if (m < dp[n - 1][i]) m = dp[n - 1][i];
	
	cout << m;
}