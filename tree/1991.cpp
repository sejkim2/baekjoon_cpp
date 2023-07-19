#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int N;
pair<char, char> tree[27];

void travel_pre(char node)
{
	if (node == '.')
		return;
	cout << node;
	travel_pre(tree[node - 'A'].first);
	travel_pre(tree[node - 'A'].second);
}

void travel_mid(char node)
{
	if (node == '.')
		return;
	travel_mid(tree[node - 'A'].first);
	cout << node;
	travel_mid(tree[node - 'A'].second);
}

void travel_back(char node)
{
	if (node == '.')
		return;
	travel_back(tree[node - 'A'].first);
	travel_back(tree[node - 'A'].second);
	cout << node;
}

int main()
{
	cin >> N;
	for(int i = 1; i<=N; i++)
	{
		char parent, left_child, right_child;
		cin >> parent >> left_child >> right_child;
		int index = parent - 'A';
		tree[index].first = left_child;
		tree[index].second = right_child;
	}
	travel_pre('A');
	cout << endl;
	travel_mid('A');
	cout << endl;
	travel_back('A');
}