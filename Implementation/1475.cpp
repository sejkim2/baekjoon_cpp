#include <iostream>
#include <algorithm>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int N;
int ar[10];
int ans;

int main()
{
    cin >> N;
    while (N > 0)
    {
        ar[N % 10]++;
        N = N / 10;
    }

    for(int i = 0; i<=9; i++)
    {
        if (i == 6 || i == 9)
            continue;
        ans = max(ans, ar[i]);        
    }
    
    ans = max(ans, (ar[6] + ar[9] + 1) / 2);
    cout << ans;
}