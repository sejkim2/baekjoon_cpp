#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int s, n, m, priority;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> s;
	for(int i = 1; i <= s; i++)
	{
		queue<pair<int, int> > q;
		priority_queue<int> p_q;
		int count = 1;
		cin >> n >> m;
		for(int j = 0; j< n; j++)
		{
			cin >> priority;
			q.push(make_pair(priority, j));
			p_q.push(priority);
		}
		while (!q.empty())
		{
			if (q.front().first < p_q.top())
			{
				q.push(q.front());
				q.pop();
			}
			else
			{
				if (q.front().second == m)
				{	
					cout << count << endl;
					break;
				}
				else
				{ 
					q.pop();
					p_q.pop();
					count++;
				}
			}
		}
	}
}
