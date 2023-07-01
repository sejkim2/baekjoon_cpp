#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int main()
{
    int a, b;
    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        else
            cout << a+b << endl;
    }
}