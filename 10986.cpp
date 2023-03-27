#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    int n, m;
    long long count;
    vector<long long> sum;
    long long mod[1001] = {0,};

    cin >> n >> m;
    sum.push_back(0);
    count = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        sum.push_back((sum[i - 1] + tmp) % m);
        mod[sum[i]]++;
    }
    for(int i = 0; i<= m; i++)
        count += (mod[i] * (mod[i] - 1)) / 2;
    cout << mod[0] + count;
}
