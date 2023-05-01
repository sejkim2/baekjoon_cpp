#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Greater_Point(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	else return p1.first < p2.first;
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

	sort(v.begin(), v.end(), Greater_Point);

	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++)
		cout << it->first << " " << it->second << '\n';
}