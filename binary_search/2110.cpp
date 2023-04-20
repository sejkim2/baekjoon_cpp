#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

typedef long long ll;
vector<ll> v;
ll n, c, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> c;
	for(int i = 0; i<n; i++)
	{
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	ll Start_dst = 1, End_dst = v[n-1] - v[0], Mid_dst;	//간격
	while (Start_dst <= End_dst)
	{
		Mid_dst = (Start_dst + End_dst) / 2;
		ll count = 1;
		ll Start = v[0], End;
		for(int i = 1; i < n; i++)
		{
			End = v[i];
			if (End - Start >= Mid_dst)
			{
				count++;
				Start = End;
			}
		}
		if (count < c)
			End_dst = Mid_dst - 1;
		else
		{
			result = max(result, Mid_dst);
			Start_dst = Mid_dst + 1;
		}
	}
	cout << result;
}
