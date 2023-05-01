#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, count = 0;
	set<int> s1, s2;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		s1.insert(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		s2.insert(tmp);
	}

	//정렬된 집합을 투포인터로 탐색
	set<int>::iterator it1 = s1.begin();
	set<int>::iterator it2 = s2.begin();

	while (it1 != s1.end() && it2 != s2.end())
	{
		if (*it1 == *it2)
		{
			it1++;
			it2++;
		}
		else if (*it1 < *it2)
		{
			count++;
			it1++;
		}
		else
		{
			count++;
			it2++;
		}
	}

	if (it1 == s1.end())
	{
		for (it2; it2 != s2.end(); it2++)
			count++;
	}
	if (it2 == s2.end())
	{
		for (it1; it1 != s1.end(); it1++)
			count++;
	}
	
	cout << count;
}