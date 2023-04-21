#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long ll;
ll n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> k;
	ll Start = 1, End = n*n, Mid;
	while (Start <= End)
	{
		ll count = 0;
		Mid = (Start + End) / 2;
		for(int i = 1; i<=n; i++)
			count += min(Mid/i, n);
		if (count < k)
			Start = Mid + 1;
		else
			End = Mid - 1;
	}
	cout << Start;
}
