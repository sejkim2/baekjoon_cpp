#include <iostream>
using namespace std;
#define endl '\n'

long long result1, result2;
int mod = 1000000007;
int n, k;

long long Pow(int up)
{
	if (up == 0)
		return (1);
	else
	{
		if (up % 2 == 0)
		{
			long long tmp = Pow(up / 2);
			return (tmp * tmp % mod);
		}
		else
			return (result2 * Pow(up - 1) % mod);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> k;
	result1 = 1;
	result2 = 1;

	for(int i = n; i>= n - k + 1; i--)
		result1 = (result1 * i) % mod;
	for(int i = 1; i<= k; i++)
		result2 = (result2 * i) % mod;
	result2 = Pow(mod - 2);
	cout << result1 * result2 % mod;
}

