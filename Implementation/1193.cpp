#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int x;

int main()
{
	cin >> x;
	int row = 1, col = 1, num = 1, dir = 1;

	while (num++ < x)
	{
		if (row == 1 && dir > 0)
		{
			col++;
			dir = -1;
		}
		else if (col == 1 && dir < 0)
		{
			row++;
			dir = 1;
		}
		else
		{
			if (dir > 0)
			{
				row--;
				col++;
			}
			else
			{
				row++;
				col--;
			}
		}
	}
	cout << row << '/' << col;
}