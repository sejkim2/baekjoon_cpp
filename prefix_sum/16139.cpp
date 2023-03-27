#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    string s;
    int sum[27][200001] = {0, };
    int ans[2001];
    int q;
    char a;
    int l, r;
    vector<pair<char, pair<int, int> > > v;

    v.push_back(make_pair(0, make_pair(0, 0)));
    cin >> s;
    cin >> q;
    for(int i = 1; i <= 26; i++)
    {
        for(int j = 1; j <= s.size(); j++)
        {
            if ('a' + i - 1 == s[j - 1])
                sum[i][j] = sum[i][j - 1] + 1;
            else
                sum[i][j] = sum[i][j - 1];
        }
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> a >> l >> r;
        v.push_back(make_pair(a, make_pair(l, r)));
        ans[i] = sum[a - 'a' + 1][r + 1] - sum[a - 'a' + 1][l];
    }
    for(int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}
