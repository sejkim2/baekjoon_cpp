#include <iostream>
#include <vector>
#define endl '\n';
using namespace std;

int ar[1000][3];
int dp[1000][3];

int find_min(int n1, int n2) {
	if (n1 > n2) {
		return n2;
	}
	else return n1;
}

int find_min(int n1, int n2, int n3) {
	int min = n1;
	if (min > n2) min = n2;
	if (min > n3) min = n3;

	return min;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ar[i][j];
		}
	}
	
	dp[0][0] = ar[0][0];
	dp[0][1] = ar[0][1];
	dp[0][2] = ar[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][j] = ar[i][j] + find_min(dp[i-1][1], dp[i-1][2]);
			else if (j == 1)
				dp[i][j] = ar[i][j] + find_min(dp[i-1][0], dp[i-1][2]);
			else
				dp[i][j] = ar[i][j] + find_min(dp[i-1][0], dp[i-1][1]);
		}
	}

	cout << find_min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
}