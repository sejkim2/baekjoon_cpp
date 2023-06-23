#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int n, x, y, ans;
int paper[101][101];

int main()
{
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> x >> y;
        for(int j = y; j < y + 10; j++)
        {
            for(int k = x; k < x + 10; k++)
                paper[j][k] = 1;
        }
    }
    for(int i = 1; i<=100; i++)
    {
        for(int j = 1; j<=100; j++)
        {
            if (paper[i][j] == 1)
                ans++;
        }
    }
    cout << ans;
}