#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'

int n, tmp;
deque<int> d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
		d.push_back(i);
	while (d.size() > 1)
	{
		d.pop_front();
		tmp = d.front();
		d.pop_front();
		d.push_back(tmp);
	}

	cout << d.front();
}
