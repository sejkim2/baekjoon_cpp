#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <vector>
#include <queue>
#include <string.h>

int n, m;
int visited[501];
vector<int> graph[501];

void init_visited()
{
	for(int i = 0; i<501; i++)
		visited[i] = 0;
}

void init_graph()
{
	for(int i = 0; i<501; i++)
	{
		graph[i].clear();
	}
}

int bfs(int node)
{
	int flag = 1;
	queue<int> q;
	q.push(node);

	while (!q.empty())
	{
		int nd = q.front();
		if (visited[nd] == 1)
			flag = 0;
		visited[nd] = 1;
		q.pop();

		for(int i = 0; i<graph[nd].size(); i++)
		{
			int next_node = graph[nd][i];
			if (visited[next_node] == 0)
				q.push(next_node);
		}
	}
	return (flag);
}

int main()
{
	int case_num = 0;
	int count_tree = 0;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		case_num++;
		init_graph();
		init_visited();
		for(int i = 0; i<m; i++)
		{
			int vertex1, vertex2;
			cin >> vertex1 >> vertex2;
			graph[vertex1].push_back(vertex2);
			graph[vertex2].push_back(vertex1);
		}
		count_tree = 0;
		for(int i = 1; i<=n; i++)
		{
			if (visited[i] == 0)
				count_tree += bfs(i);
		}

		if (count_tree == 0)
			cout << "Case " << case_num << ": " << "No trees." << endl;
		else if (count_tree == 1)
			cout << "Case " << case_num << ": " << "There is one tree." << endl;
		else
			cout << "Case " << case_num << ": " << "A forest of " << count_tree << " trees." << endl;
	}
}