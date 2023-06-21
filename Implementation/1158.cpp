#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <queue>
#include <vector>

int N, K;
int Visited[5001];
queue<int> q1, q2;

int main()
{
	cin >> N >> K;
	for(int i = 1; i<=N; i++)	
		q1.push(i);
	for(int i = 1; i<=N; i++)
	{
		int cnt = K - 1;
		while (cnt--)
		{
			q1.push(q1.front());
			q1.pop();
		}
		q2.push(q1.front());
		q1.pop();
	}
	cout << "<";
	while (q2.size() > 1)
	{
		cout << q2.front() << ", ";
		q2.pop();
	}
	cout << q2.front() << ">";
}