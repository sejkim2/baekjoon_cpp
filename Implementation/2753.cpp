#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'
using namespace std;

int n;

int main()
{
	cin >> n;
	if (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0))
		cout << "1";
	else cout << "0";
}