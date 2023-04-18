#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long ll;
ll Start, End, Mid, total, result;
int n, k;
int lan[10001];
int Max;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> k >> n;
	for(int i = 0; i<k; i++)
	{
		cin >> lan[i];
		Max = max(Max, lan[i]);
	}
	Start = 1;
	End = Max;
	while (Start <= End)
	{
		Mid = (Start + End) / 2;
		total = 0;
		for(int i = 0; i<k; i++)
			total += (lan[i] / Mid);
		if (total < n)
			End = Mid - 1;
		else
		{
			Start = Mid + 1;
			result = max(result, Mid);
		}
	}
	cout << result;
}
