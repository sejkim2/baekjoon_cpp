#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int* arr;

	scanf("%d", &n);

	arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	delete[] arr;
}