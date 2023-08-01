#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>
int N;
int A[1001];
int dp[1001];

int main(void)
{
    fast_io;
    cin >> N;
    for(int i = 1; i<=N; i++)
    {
        cin >> A[i];
        dp[i] = 1;
    }

    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }   
    }
    int ans = 0;
    for(int i = 1; i<=N; i++)
        ans = max(dp[i], ans);
    cout << ans;
}