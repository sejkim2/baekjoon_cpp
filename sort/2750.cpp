#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

int main()
{
	int n, ar[1000];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ar[i]);

	std::sort(ar, ar + n);
	for (int i = 0; i < n; i++)
		printf("%d\n", ar[i]);
}