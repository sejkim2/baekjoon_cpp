#include <iostream>
#define endl '\n';
using namespace std;

int f[41];
int count_fib = 0;
int count_fibonacci = 0;

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		count_fib++;
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n)
{
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];

	count_fibonacci = n - 2;
	return f[n];
}

int main()
{
	int n;
	cin >> n;

	fib(n);
	fibonacci(n);

	cout << count_fib << " " << count_fibonacci;
}