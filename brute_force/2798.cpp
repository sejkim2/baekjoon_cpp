#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	int sum = 0, max = 0;

	cin >> n >> m;

	int *ar = new int[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = ar[i] + ar[j] + ar[k];

				if (sum <= m && sum > max)
					max = sum;
				sum = 0;
			}
		}
	}

	cout << max;
}