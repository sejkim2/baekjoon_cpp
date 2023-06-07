#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

#define INF 2000000000
int N, Start, End, ans, Minus, Plus;
vector<int> v;

int main()
{
	cin >> N;
	int max_value = INF;

	for(int i = 0; i<N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	Start = 0;
	End = N - 1;
	ans = INF;

	while (Start < End)
	{
		int mix = v[Start] + v[End];

		if (ans > abs(mix))
		{
			ans = abs(mix);
			Plus = v[End];
			Minus = v[Start];
		}
		if (mix < 0)	//0보다 작으므로 커져야 함 (오른쪽으로 이동 필요)
			Start++;
		else
			End--;
	}
	cout << Minus << ' ' << Plus;
}