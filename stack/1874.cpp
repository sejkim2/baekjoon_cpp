#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define endl '\n'

int n;
int ar[100001];
string str;
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int num = 1;
	int flag = 0;

	cin >> n;
	for(int i = 1; i<= n; i++)
		cin >> ar[i];

	s.push(0);
	for(int i = 1; i<= n; i++)
	{
		while (ar[i] > s.top())
		{
			s.push(num++);
			str += '+';
		}
		if (ar[i] == s.top())
		{
			s.pop();
			str += '-';
		}
		else if (ar[i] < s.top())
		{
			flag = -1;
			break;
		}
	}
	if (flag == -1)
		cout << "NO" << endl;
	else
	{
		for(int i = 0; i<str.length(); i++)
		{
			cout << str[i] << endl;
		}
	}
}
