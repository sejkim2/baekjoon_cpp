#include <iostream>
#include <deque>
#include <string>
using namespace std;
#define endl '\n'

deque<int> d;
string str;
int n, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> str;
		if (str.compare("push_front") == 0)
		{
			cin >> x;
			d.push_front(x);
		}
		else if (str.compare("push_back") == 0)
		{
			cin >> x;
			d.push_back(x);
		}
		else if (str.compare("pop_front") == 0)
		{
			if (d.empty()) cout << -1 << endl;
			else
			{
				cout << d.front() << endl;
				d.pop_front();
			}
		}
		else if (str.compare("pop_back") == 0)
		{
			if (d.empty()) cout << -1 << endl;
			else
			{
				cout << d.back() << endl;
				d.pop_back();
			}
		}
		else if (str.compare("size") == 0)
			cout << d.size() << endl;
		else if (str.compare("empty") == 0)
			cout << d.empty() << endl;
		else if (str.compare("front") == 0)
		{
			if (d.empty()) cout << -1 << endl;
			else cout << d.front() << endl;
		}
		else if (str.compare("back") == 0)
		{
			if (d.empty()) cout << -1 << endl;
			else cout << d.back() << endl;
		}
	}
}
