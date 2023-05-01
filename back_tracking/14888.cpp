#include <iostream>
#include <limits.h>
#include <algorithm>
#define endl '\n';
using namespace std;

//ar_cul[]은 각각 +, -, *, /;
int ar[100], ar_operator[4];
int n;

int Max = INT_MIN, Min = INT_MAX;

void fuc(int index, int result)
{
	if (index == n - 1)
	{
		Max = max(Max, result);
		Min = min(Min, result);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (ar_operator[i] > 0)
		{
			ar_operator[i]--;

			//plus
			if (i == 0)
				fuc(index + 1, result + ar[index + 1]);
			//minus
			else if (i == 1)
				fuc(index + 1, result - ar[index + 1]);
			//multi
			else if (i == 2)
				fuc(index + 1, result * ar[index + 1]);
			//div
			else
				fuc(index + 1, result / ar[index + 1]);

			ar_operator[i]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	for (int i = 0; i < 4; i++)
		cin >> ar_operator[i];

	fuc(0, ar[0]);

	cout << Max << '\n' << Min;
}