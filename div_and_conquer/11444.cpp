#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

typedef long long Size;
typedef vector<vector<Size> > arr;

Size n;
Size Value = 1000000007;

arr operator * (arr& v1, arr& v2)
{
	arr tmp(2, vector<Size>(2));
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<2; j++)
		{
			for(int k = 0; k<2; k++)
				tmp[i][j] += v1[i][k] * v2[k][j];
			tmp[i][j] %= Value;
		}
	}
	return (tmp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	arr res = {{1, 0}, {0, 1}};
	arr v = {{1, 1}, {1, 0}};

	cin >> n;
	while (n > 0)
	{
		if (n % 2 != 0)
			res = res * v;
		v = v * v;
		n = n / 2;
	}
	cout << res[0][1];
}
