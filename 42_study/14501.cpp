#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>

int ans;
int N;
pair<int, int> table[16];
int dp[16];

int main(void)
{
    fast_io;

    cin >> N;
    for(int i = 1; i<= N; i++)
    {
        int t, p;
        cin >> t >> p;
        table[i] = make_pair(t, p);
    }
    
    for(int i = 1; i<=N + 1; i++)
    {
        int consulting_time = table[i].first;
        int consulting_pay = table[i].second;
        dp[i] = max(dp[i], ans);
        if (consulting_time + i <= N + 1)
            dp[i + consulting_time] = max(dp[i + consulting_time],\
            consulting_pay + dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}