#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int ar1[100001];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for(int i = 0; i< n; i++)
		cin >> ar1[i];
	sort(ar1, ar1 + n);
	cin >> m;
	for(int i = 0; i<m; i++)
	{
		int tmp;
		cin >> tmp;
		cout << binary_search(ar1, ar1 + n, tmp) << endl;
	}
}
