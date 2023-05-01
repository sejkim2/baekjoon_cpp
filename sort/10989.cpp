#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int v[10001] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v[tmp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while (v[i] != 0)
		{
			cout << i << '\n';
			v[i]--;
		}
	}
}

