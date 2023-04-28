#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'

typedef long long ll;
int n;
ll x;
priority_queue<ll> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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
