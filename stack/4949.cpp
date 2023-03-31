#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define endl '\n'

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	while (1)
	{
		getline(cin, str);
		// cin >> str;
		if (str.compare(".") == 0)
			break;
		int j = 0;
		int flag = 1;
		stack<char> s;
		while (str[j] != '.')
		{
			if (str[j] == '(' || str[j] == '[')
				s.push(str[j]);
			else if (str[j] == ')')
			{
				if (s.empty() || s.top() == '[')
				{
					flag = 0;
					break;
				}
				else
					s.pop();
			}
			else if (str[j] == ']')
			{
				if (s.empty() || s.top() == '(')
				{
					flag = 0;
					break;
				}
				else
					s.pop();
			}
			j++;
		}
		if (flag == 1 && s.empty())
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
