#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int X;
int ans;

int main(void)
{
    fast_io;
    
    cin >> X;
    for (int i = 0; i <= 6; i++)
    {
        if (X & (1 << i))
            ans++;
    }
    cout << ans;
}
