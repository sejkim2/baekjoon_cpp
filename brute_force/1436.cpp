#pragma warning(disable:4996)
#include <stdio.h>

bool is666(int num)
{
	int count = 0;
	while (num > 1)
	{
		if (num % 10 == 6)
			count++;
		else count = 0;

		if (count == 3)
			break;
		num /= 10;
	}
	if (count >= 3)
		return true;
	else return false;
}

int main()
{
	int n, num = 666;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		while (!is666(num))
			num++;
		num++;
	}

	printf("%d", num - 1);
}