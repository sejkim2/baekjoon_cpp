#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>

int n, k;
int ar[10001];
int dp[10001];

int main()
{
    fast_io;
    cin >> n >> k;
    dp[0] = 0;
    for(int i = 1; i<=n; i++)
        cin >> ar[i];
    for(int i = 1; i<=k; i++)
        dp[i] = 999999;

    for(int i = 1; i<=n; i++)
    {
        int cur_money = ar[i];
        for(int j = cur_money; j <= k; j++)
            dp[j] = min(dp[j], dp[j - cur_money] + 1);
    }
    if (dp[k] == 999999)
        cout << -1;
    else
        cout << dp[k];
}