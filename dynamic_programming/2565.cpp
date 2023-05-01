#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n';

int main()
{
    int n;
    int dp[501];
    vector<pair<int, int> > v;
    cin >> n;

    v.push_back(make_pair(0, 0));
    for(int i = 1; i <= n; i++)
    {
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
    sort(v.begin() + 1, v.end());
        
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j <= i; j++)
        {
            if (v[i].second > v[j].second)
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    cout << n - *max_element(dp + 1, dp + n + 1);
}