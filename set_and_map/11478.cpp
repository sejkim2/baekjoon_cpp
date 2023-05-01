#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	set<string> s;

	cin >> str;
	int strSize = str.length();

	for (int i = 0; i < strSize; i++)
	{
		int p1 = 0;
		int p2 = p1 + i;
		while (p1 != strSize && p2 != strSize)
		{
			string tmp;
			tmp.append(str, p1, p2 - p1 + 1);
			s.insert(tmp);
			p1++;
			p2++;
		}
	}

	cout << s.size();
}