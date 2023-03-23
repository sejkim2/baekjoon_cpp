#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    int n, m;
    vector<int> v1;
    vector<pair<int, int> > v2;
    int dp[100001];

    cin >> n >> m;
    dp[0] = 0;
    v1.push_back(0);

    for(int i = 1; i<=n; i++)
    {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
        dp[i] = dp[i -1] + tmp;
    }

    v2.push_back(make_pair(0, 0));
    for(int i = 1; i<=m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v2.push_back(make_pair(tmp1, tmp2));
    }

    for(int i = 1; i<=m; i++)
        cout << dp[v2[i].second] - dp[v2[i].first - 1] << endl;
}
