#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
#define endl '\n'

int main()
{
    int n, k, result, tmp;
    int sum[100004];
    
    cin >> n >> k;
    sum[0] = 0;
    result = INT_MIN;
    for(int i = 1; i<=n; i++)
    {
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }
    for(int i = k; i<= n; i++)
        result = max(result, sum[i] - sum[i - k]);
    cout << result;
}
