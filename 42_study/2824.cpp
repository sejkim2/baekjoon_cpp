#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>
#include <cmath>
#define MAX_VALUE 1000000000

int N, M;
int A[1001];
int B[1001];
long long result;

int eculidean(int a, int b)
{
    while (1)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
        if (b == 0)
            break;
    }
    return (a);
}

int main(void)
{
    int flag = 0;
    result = 1;
    cin >> N;
    for(int i = 0; i<N; i++)
        cin >> A[i];
    cin >> M;
    for(int i = 0; i<M; i++)
        cin >> B[i];
    
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            int gcd;
            if (A[i] < B[j])
                gcd = eculidean(B[j], A[i]);
            else
                gcd = eculidean(A[i], B[j]);
            result *= gcd;
            if (result >= MAX_VALUE)
            {
                flag = 1;
                result %= MAX_VALUE;
            }
            A[i] /= gcd;
            B[j] /= gcd;
        }
    }
    if (flag == 0)
        cout << result;
    else
        printf("%09lld", result);
}