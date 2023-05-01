#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int i, j, n, m = 2147483647;
	cin >> n;
	for(i = 0; i<= n/3; i++)
	{
		for(j = 0; j <= n/5; j++)
		{
			if (i * 3 + j * 5 == n)
			{
				m = min(i + j, m);
				break;
			}
		}
	}
	
	if (m == 2147483647)
		m = -1;
	cout << m;
}
