#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n, result;
vector<int> v;

// int lower_bound_func(int Value)
// {
// 	int Start = 0, End = v.size() - 1, Mid;
// 	while (Start < End)
// 	{
// 		Mid = (Start + End) / 2;
// 		if (Value < v[Mid])
// 			End = Mid;
// 		else
// 			Start = Mid + 1;
// 	}
// 	return (End);
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for(int i = 0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		if (v.size() == 0 || v.back() < tmp)
			v.push_back(tmp);
		else
		{
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), tmp);
			*iter = tmp;
		}
		// else
		// {
		// 	int index = lower_bound_func(tmp);
		// 	v[index] = tmp;
		// }
	}
	cout << v.size();
}
