#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main()
{
	int n, i, j, sum = 0, flag = 0;
	
	cin >> n;
	
	for (i = 1; i < n; i++)
	{
		sum = i;
		j = i;
		while (j >= 1)
		{
			sum = sum + (j % 10);
			j = j / 10;
		}
		if (sum == n)
		{
			cout << i;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		cout << 0;
}
