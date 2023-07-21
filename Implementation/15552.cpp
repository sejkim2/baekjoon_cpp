#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int n;

int main()
{
    fast_io;
    
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << a+b << endl;
    }
}