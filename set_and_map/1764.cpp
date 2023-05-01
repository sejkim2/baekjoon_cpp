#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	set<string> s, s2;

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
			s2.insert(tmp);
	}
	cout << s2.size() << '\n';

	for (set<string>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << *it << '\n';
}