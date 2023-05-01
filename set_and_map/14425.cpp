#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n, m, count = 0;
	set<string> s;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		string tmp;
		cin >> tmp;

		if (s.find(tmp) != s.end())
			count++;
		
	}

	cout << count;
}