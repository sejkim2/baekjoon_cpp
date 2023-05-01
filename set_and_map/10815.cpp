#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<int> v1, v2;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}
	
	sort(v1.begin(), v1.end());
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		v2.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		if (binary_search(v1.begin(), v1.end(), v2[i]))
			cout << "1";
		else cout << "0";
		cout << " ";
	}
}