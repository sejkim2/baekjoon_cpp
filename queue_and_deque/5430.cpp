#include <iostream>
#include <queue>
#include <deque>
#include <string>
using namespace std;
#define endl '\n'

int t, n;
string p, input;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> t;
	for(int i = 1; i<= t; i++)
	{
		deque<int> d;
		int rev = 1;
		int flag = 0;
		string output = "";
		cin >> p;
		cin >> n;
		cin >> input;
		for(int j = 0; j < input.length(); j++)
		{
			if (input[j] >= '0' && input[j] <= '9')
				output += input[j];
			else if ((input[j] == ',' || input[j] == ']'))
			{
				if (!output.empty())
				{
					d.push_back(stoi(output));
					output = "";
				}
			}
		}
		for(int j = 0; j < p.length(); j++)
		{
			if (p[j] == 'R') 
				rev *= -1;
			else if (p[j] == 'D')
			{
				if (d.empty())
				{
					flag = 1;
					break;
				}
				if (rev > 0) d.pop_front();
				else d.pop_back();
			}
		}
		if (flag == 1)
			output = "error";
		else
		{
			output = '[';
			if (rev > 0)
			{
				for(int j = 0; j < d.size(); j++)
				{
					if (j == d.size() - 1)
						output += to_string(d[j]); 
					else
						output += to_string(d[j]) + ',';
				}
			}
			else
			{
				for(int j = d.size() - 1; j >= 0; j--)
				{
					if (j == 0)
						output += to_string(d[j]);
					else 
						output += to_string(d[j]) + ',';
				}
			}
			output += ']';
		}
		cout << output << endl;
	}
}
