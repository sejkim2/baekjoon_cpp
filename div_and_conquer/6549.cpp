#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long ll;
ll h[100001];
ll seg[1000001];
int n;

int make_seg_tree(int seg_index, int h_start, int h_end)
{
	if (h_start == h_end)
		return (seg[seg_index] = h[h_start]);
	else
	{
		make_seg_tree(seg_index * 2, h_start, (h_start + h_end) / 2);
		make_seg_tree(seg_index * 2 + 1, (h_start + h_end) / 2 + 1, h_end);
		seg[seg_index] = max(seg[seg_index * 2], seg[seg_index * 2 + 1]);
	}
}

int query(int start, int end)
{
	int sum = 0;
	while (start < end)
	{
		if (start%2 == 1) sum += seg[start];
		start = (start + 1) % 2; 
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for(int i = 0; i<n; i++)
			cin >> h[i];
		make_seg_tree(1, 0, n - 1);
	}
}
