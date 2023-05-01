#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mySort(pair<int, int>p1, pair<int, int>p2)
{
	return p1.first < p2.first;
}

int main()
{
	int n, count = 0;
	vector<pair<int, int>> v;

	cin >> n;
	vector<int> v2(n, 0);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		v.push_back(pair<int, int>(tmp, i));
	}

	sort(v.begin(), v.end(), mySort);
	
	v2[v[0].second] = count;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first != v[i - 1].first)
		{
			count++;
			v2[v[i].second] = count;
		}
		else v2[v[i].second] = v2[v[i-1].second];
	}

	for (int i = 0; i < n; i++)
		cout << v2[i] << " ";
}