#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> v;
int n, k;

int main()
{
	int i = 0;
	int cnt = 0;

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
