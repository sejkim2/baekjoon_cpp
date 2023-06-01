#include <iostream>
#include <algorithm>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int n, x, cnt;
vector<int> v;

int main()
{
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> x;

	sort(v.begin(), v.end());
	int p1 = 0, p2 = n - 1;
	while (p1 < p2)
	{
		if (v[p1] + v[p2] < x)
			p1++;
		else if (v[p1] + v[p2] > x)
			p2--;
		else
		{
			p1++;
			p2--;
			cnt++;
		}
	}
	cout << cnt;
}
