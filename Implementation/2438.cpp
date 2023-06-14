#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'
using namespace std;

int N;

int main()
{
	cin >> N;
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j< i + 1; j++)
			cout << "*";
		cout << endl;
	}
}