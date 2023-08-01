#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>
int n;
int drink[10001];
int dp[10001];

int main(void)
{
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> drink[i];

    dp[1] = drink[1];
    dp[2] = dp[1] + drink[2];
    dp[3] = max(max(dp[1]+drink[3], dp[2]), drink[2]+drink[3]);

    for(int i = 4; i <= n; i++)
        dp[i] = max(max(dp[i-2] + drink[i], dp[i-3] + drink[i-1] + drink[i]), dp[i-1]);
    cout << dp[n];
}