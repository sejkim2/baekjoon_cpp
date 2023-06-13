#include <iostream>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	cout << (A+B)%C << endl;
	cout << ((A%C) + (B%C))%C << endl;
	cout << (A*B)%C << endl;
	cout << ((A%C) * (B%C))%C << endl;
}