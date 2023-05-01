#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

int n, x;

struct cmp {
    bool operator()(int n1, int n2)
    {
        if (abs(n1) == abs(n2))
            return n1 > n2;
            // return (n1 < n2 ? 0 : 1);
        else return (abs(n1) > abs(n2));
    }
};

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
    priority_queue<int, vector<int>, cmp> pq;

	for(int i = 0; i<n; i++)
	{
		cin >> x;
		if (x != 0)
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