#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

typedef long long ll;
ll A, B, C;
ll ans;
int ar[10];

int main()
{
	cin >> A;
	cin >> B;
	cin >> C;
	ans = A * B * C;
	while (ans > 0)
	{
		ar[ans % 10]++;
		ans = ans / 10;
	}
	for(int i = 0; i<=9; i++)
		cout << ar[i] << endl;
}
