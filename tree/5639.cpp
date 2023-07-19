#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define endl '\n'
using namespace std;

int tree[10001];

void postOrder(int Start, int End)
{
	if (Start >= End)
		return;
	int parent = Start;
	int left_child = Start + 1;
	int right_child = left_child;
	while (right_child < End && tree[parent] > tree[right_child])
		right_child++;
	postOrder(left_child, right_child);
	postOrder(right_child, End);
	cout << tree[parent] << endl;
}

int main()
{
	int node;
	int index = 0;

	while (!(cin >> node).eof())
		tree[index++] = node;
	postOrder(0, index);
}