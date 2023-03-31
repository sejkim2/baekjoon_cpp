#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define endl '\n'

int n, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string str;
	stack<int> s;

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> str;
		if (str.compare("push") == 0)
		{
			cin >> x;
			s.push(x);
		}
		else if (str.compare("pop") == 0)
		{
			if (s.empty())
				cout << -1 << endl;
			else 
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (str.compare("size") == 0)
			cout << s.size() << endl;
		else if (str.compare("empty") == 0)
		{
			if (s.empty())
				cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (str.compare("top") == 0)
		{
			if (s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
	}	
}
