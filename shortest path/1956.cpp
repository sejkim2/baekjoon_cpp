#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <vector>

int V, E, a, b, c;
vector<pair<int, int> > v;

int main()
{
	cin >> V >> E;
	for(int i = 0; i<E; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	
}