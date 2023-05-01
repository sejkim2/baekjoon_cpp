#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mySort(pair<int, string> p1, pair<int, string> p2)
{
	return p1.first < p2.first;
}

int main()
{	
	int n;
	vector<pair<int, string>> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, string> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	stable_sort(v.begin(), v.end(), mySort);

	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << '\n';
}