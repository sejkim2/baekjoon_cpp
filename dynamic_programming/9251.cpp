#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

int main()
{
    string s1, s2;
    int dp[1001][1001];
    int i, j;

    cin >> s1 >> s2;
    for(int i = 0; i <= s1.length(); i++)
        dp[i][0] = 0;
    for(int j = 0; j <= s2.length(); j++)
        dp[0][j] = 0;

    for(i = 1; i<= s1.length(); i++)
    {
        for(j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[i - 1][j - 1];
}