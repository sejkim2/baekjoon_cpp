#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>
#define INF 9999999
int V, E, a, b, c, ans;
int city[401][401];

void floyed_warshall()
{
	for(int i = 1; i<=V; i++)
	{
		for(int j = 1; j<=V; j++)
		{
			for(int k = 1; k <= V; k++)
				city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
		}
	}
}

void init_city()
{
	for(int i = 1; i<=V; i++)
	{
		for(int j = 1; j<=V; j++)
			city[i][j] = INF;
	}
}

int main()
{
	cin >> V >> E;
	
	init_city();

	for(int i = 0; i<E; i++)
	{
		cin >> a >> b >> c;
		city[a][b] = c;
	}

	floyed_warshall();
	ans = INF;
	for(int i = 1; i<=V; i++)
		ans = min(ans, city[i][i]);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;				
}