#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define endl '\n'

int t;
string str;
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> str;
		int j = 0;
		int isTrue = 1;
		while (j < str.length())
		{
			if (str[j] == '(')
				s.push(str[j]);
			else
			{
				if (s.empty())
				{
					isTrue = 0;
					break;
				}
				else
					s.pop();
			}
			j++;
		}
		if (isTrue && s.empty())
			cout << "YES" << endl;
		else cout << "NO" << endl;
		while (!s.empty())
			s.pop();
	}
}
