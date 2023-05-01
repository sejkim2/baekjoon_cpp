#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int ar[5];
	int sum = 0;
	for(int i = 0; i<5; i++)
	{
		cin >> ar[i];
		sum += ar[i];
	}
	sort(ar, ar + 5);
	cout << sum / 5 << endl << ar[2];
}