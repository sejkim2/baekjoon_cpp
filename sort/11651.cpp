#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mySort(pair<int, int>&p1, pair<int, int>&p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else return p1.second < p2.second;
}

int main()
{
	int n;
	vector<pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;

		v.push_back(p);
	}

	sort(v.begin(), v.end(), mySort);

	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << '\n';
}