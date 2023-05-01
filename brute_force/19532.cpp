#include <iostream>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	int flag = 0;
	int x, y;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	for(x = -999; x <= 999; x++)
	{
		for(y = -999; y <= 999; y++)
		{
			if (a * x + b * y == c && d * x + e * y == f)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << x << " " << y;
			break; 
		}
	}	
}
