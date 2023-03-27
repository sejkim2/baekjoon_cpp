#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int n, k;
vector<int> v;

int main()
{
	int cnt = 0;
	int i = 0;

	cin >> n >> k;
	for(i = 0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	i--;

	while (k)
	{
		while (v[i] > k)
			i--;
		cnt += k / v[i];
		k %= v[i];
	}

	cout << cnt;
}
