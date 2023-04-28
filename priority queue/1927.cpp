#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'

int n, x;
priority_queue<int, vector<int>, greater<int> > pq;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i<n; i++)
	{
		cin >> x;
		if (x > 0)
			pq.push(x);
		else
		{
			if (pq.empty())
				cout << 0 << endl;
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
	}
}