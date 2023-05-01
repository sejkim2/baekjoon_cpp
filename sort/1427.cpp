#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> v;

	cin >> n;
	while (n > 0)
	{
		v.push_back(n % 10);
		n = n / 10;
	}

	sort(v.begin(), v.end(), greater<int>());
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it;
}