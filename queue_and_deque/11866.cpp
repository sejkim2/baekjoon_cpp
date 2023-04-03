#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define endl '\n'

int n, k;
queue<int> q;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	str += "<";

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		q.push(i);
	for(int i = 1; i < n; i++)
	{
		int j = 1;
		while (j < k)
		{
			q.push(q.front());
			q.pop();
			j++;
		}
		str += to_string(q.front());
		str += ", ";
		q.pop();
	}
	str += to_string(q.front());
	str += ">";
	cout << str << endl;
}
