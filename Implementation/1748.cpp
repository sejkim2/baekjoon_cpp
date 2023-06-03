#include <iostream>
#include <cmath>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int N;

int main()
{
    int N;
    int ans = 0;

    cin >> N;

    if (N < 10)
        ans = N;
    else
    {
        for(int i = 1; i<=N; i *= 10)
            ans += N - i + 1;
    }
    cout << ans;
}