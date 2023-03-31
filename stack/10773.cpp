#include <iostream>
#include <stack>
using namespace std;
#define endl '\n'

int k, sum;
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			sum -= s.top();
			s.pop();
		}
		else 
		{	
			s.push(tmp);
			sum += tmp;
		}
	}

	cout << sum;
}
