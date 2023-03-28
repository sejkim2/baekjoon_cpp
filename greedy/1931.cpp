#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int n;
vector<pair<int, int> > v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int last = 0;
	int count = 1;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());
	last = v[0].first;

	for(int i = 1; i < n; i++)
	{
		if (last <= v[i].second)
		{
			last = v[i].first;
			count++;
		}
	}

	cout << count;
}
