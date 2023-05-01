#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mySort(string &str1, string &str2)
{
	if (str1.size() == str2.size())
		return str1 < str2;
	else return str1.size() < str2.size();
}

int main()
{
	int n;
	vector<string> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		v.push_back(str);
	}

	sort(v.begin(), v.end(), mySort);

	cout << v[0] << '\n';
	for (int i = 1; i < n; i++)
	{
		if (v[i] == v[i - 1]) continue;
		else cout << v[i] << '\n';
	}
}