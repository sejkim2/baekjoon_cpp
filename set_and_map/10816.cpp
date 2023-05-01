#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<int> v(20000001, 0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v[tmp + 10000000]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		cout << v[tmp + 10000000] << " ";
	}
	
}