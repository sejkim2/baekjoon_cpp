#include <iostream>
#define endl '\n';
using namespace std;

long long fibo[1000001];
int n;

void fib()
{
	fibo[0] = fibo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 15746;
	}
}

int main()
{
	cin >> n;
	fib();

	cout << fibo[n];
}