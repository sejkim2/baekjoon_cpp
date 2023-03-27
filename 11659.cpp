#include <iostream>
using namespace std;
#define endl '\n'

int main()
{
    int n, m, tmp;
    int sum[100001];

    cin >> n >> m;
    sum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }

    for(int i = 1; i<= m; i++)
    {
        cin >> n >> m;
        cout << sum[m] - sum[n - 1] << endl;
    }
}
