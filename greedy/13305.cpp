#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int n;
long long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	long long min_cost;
	vector<long long> distance;	
	vector<long long> cost;
	int j = 0;
	distance.push_back(0);
	cost.push_back(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int dis;
		cin >> dis;
		distance.push_back(dis);
	}
	for(int i = 1; i<= n; i++)
	{
		int cos;
		cin >> cos;
		cost.push_back(cos);
	}

	min_cost = cost[1];
	for(int i = 1; i < n; i++)
	{
		if (cost[i] <= min_cost)
			min_cost = cost[i];
		result += min_cost * distance[i];
	}

	cout << result;
}
