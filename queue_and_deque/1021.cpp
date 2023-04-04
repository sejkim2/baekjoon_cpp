#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'

deque<int> d;
int ar[51], cnt;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cnt = 0;
	cin >> n >> m;
	for(int i = 0; i< n; i++)
		d.push_back(i+1);
	for(int i = 0; i< m; i++)
		cin >> ar[i];
	for(int i = 0; i < m; i++)
	{
		int index = 0;
		while (d[index] != ar[i])
			index++;
		if (index < d.size() - index)
		{
			while (d.front() != ar[i])
			{
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
		}
		else
		{
			while (d.front() != ar[i])
			{
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
		}
		d.pop_front();
	}
	cout << cnt;
}
