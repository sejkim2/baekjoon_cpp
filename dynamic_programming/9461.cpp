#include <iostream>
#define endl '\n';
using namespace std;

long long ar[101];

long long dp(int n)
{
	for (int i = 4; i <= n; i++)
		ar[i] = ar[i - 2] + ar[i - 3];

	return ar[n];
}

int main()
{
	int n;
	ar[1] = ar[2] = ar[3] = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		cout << dp(tmp) << endl;
	}
}