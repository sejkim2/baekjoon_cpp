#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int ar[10001];

int main()
{
	int n, x;
	cin >> n >> x;
	for(int i = 0; i<n; i++)
		cin >> ar[i];
	for(int i = 0; i<n; i++)
	{
		if (ar[i] < x)
			cout << ar[i] << " ";
	}
}