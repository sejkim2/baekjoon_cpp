#include <iostream>
#include <queue>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int N, K;
bool visited[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
// priority_queue<pair<int, int> > q;	//bfs는 가중치가 같을 때만 사용 가능하지만
// //해당 문제는 순간이동을 하는 경우 0초가 걸리므로 가중치가 1초일 때와 다르다.-> 다익스트라 혹은 우선순위 큐 사용
// //first : -weight(sec), second : pos (min heap을 위해 음수 처리) 

int bfs()
{
	q.push(make_pair(0, N));
	visited[N] = true;

	while (!q.empty())
	{
		int sec = q.top().first;
		int pos = q.top().second;
		if (pos == K)
			return sec;
		q.pop();

		if (pos * 2 <= 100000 && visited[pos * 2] == false)	//2배 움직였을 때 0이면 방문처리가 안된 것으로 볼 수 있으므로 방문기록은 1이상으로 기록
		{
			visited[pos * 2] = true;
			q.push(make_pair(sec, pos * 2));
		}
		if (pos + 1 <= 100000 && visited[pos + 1] == false)	//visited[]가 0일 때 방문하는 순간 가장 빠른 시간에 도착한 루트
		{
			visited[pos + 1] = true;
			q.push(make_pair((sec + 1), pos + 1));
		}
		if (pos - 1 >= 0 && pos - 1 <= 100000 && visited[pos - 1] == false)
		{
			visited[pos - 1] = true;
			q.push(make_pair((sec + 1), pos - 1));
		}
	}
	return (0);
}

int main()
{
	cin >> N >> K;
	cout << bfs();
}
