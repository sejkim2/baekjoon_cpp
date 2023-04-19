#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long ll;
ll n, m, result, trees, Mid, Start, End;
ll height[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		cin >> height[i];
		End = max(End, height[i]);
	}
	Start = 0;
	while (Start <= End)
	{
		Mid = (Start + End) / 2;
		trees = 0;
		for(int i = 0; i<n; i++)
		{
			ll h;
			if (height[i] > Mid)
				h = height[i] - Mid;
			else h = 0;
			trees += h;
		}
		if (trees < m)
			End = Mid - 1;
		else
		{
			Start = Mid + 1;
			result = max(result, Mid);
		}
	}
	cout << result;
}
