#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	map<int, string> m1;
	map<string, int> m2;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string str;
		pair<int, string> p1;
		pair<string, int> p2;

		cin >> str;
		p1.second = p2.first = str;
		p1.first = p2.second = i;

		m1.insert(p1);
		m2.insert(p2);
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (str[0] >= 'A' && str[0]  <= 'z')
			cout << m2[str] << '\n';
		else cout << m1[stoi(str)] << '\n';
	}
}
