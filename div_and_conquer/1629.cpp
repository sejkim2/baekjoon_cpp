#include <iostream>
using namespace std;
#define endl '\n'

long long a, b, c;
long long result;

long long Pow(int b)
{
	if (b == 0)
		return (1);
	else
	{
		long long tmp = Pow(b / 2);
		tmp = tmp * tmp % c;
		if (b % 2 == 0)	return (tmp);
		else return (tmp * a % c); 
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> a >> b >> c;

	result = Pow(b);
	cout << result;
}
