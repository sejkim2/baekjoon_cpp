#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define endl '\n'

int n, x;
string str;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i<= n; i++)
	{
		cin >> str;
		if (str.compare("push") == 0)
		{
			cin >> x;
			q.push(x);
		}
		else if (str.compare("pop") == 0)
		{
			if (!q.empty())	
			{
				cout << q.front() << endl;
				q.pop();
			}
			else cout << "-1" << endl;
		}
		else if (str.compare("size") == 0)
			cout << q.size() << endl;
		else if (str.compare("empty") == 0)
			cout << q.empty() << endl;
		else if (str.compare("front") == 0)
		{
			if (!q.empty())	cout << q.front() << endl;
			else cout << "-1" << endl;
		}
		else if (str.compare("back") == 0)
		{
			if (!q.empty())	cout << q.back() << endl;
			else cout << "-1" << endl;
		}
	}
}
