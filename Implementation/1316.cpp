#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cout.tie(false), cin.tie(false)
#define endl '\n'
using namespace std;

#include <string.h>

int N, ans;
string str;

int main()
{
	cin >> N;
	while (N-- > 0)
	{
		cin >> str;
		char ch;
		bool isTrue = true;
		for(int i = 0; i<str.size(); i++)
		{
			ch = str[i];
			while (str[i + 1] == ch)
				i++;
			for(int j = i + 1; j < str.size(); j++)
			{
				if (str[j] == ch)
				{
					isTrue = false;
					break;
				}
			}
			if (isTrue == false)
				break;
		}
		if (isTrue == true)
			ans++;
	}

	cout << ans;
}