#include <iostream>
#include <algorithm>
#define endl '\n';
using namespace std;

int main()
{
	int num;
	int stair[300];
	int sum[300];
	int i;

	cin >> num;
	for (i = 0; i < num; i++)
		cin >> stair[i];

	sum[0] = stair[0];
	sum[1] = stair[0] + stair[1];
	sum[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (i = 3; i < num; i++)
		sum[i] = max(sum[i - 2] + stair[i], sum[i - 3] + stair[i - 1] + stair[i]);

	cout << sum[num - 1];
}