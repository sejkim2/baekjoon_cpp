#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	map<string, string, greater<string> > m;
	string str, name;

	cin >> n;
	for(int i = 1; i<= n; i++)
	{
		cin >> name;
		cin >> str;
		// m.insert(make_pair(name, str));
		m[name] = str;
	}
	map<string, string>::iterator iter;
	for(iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second == "enter")
			cout << iter->first << endl;
	}
}
