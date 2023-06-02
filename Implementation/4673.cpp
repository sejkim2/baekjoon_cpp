#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int ar[100000];

int func(int n)
{
    int i, sum = n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return (sum);
}

int main()
{
    for(int constructor = 1; constructor<= 10000; constructor++)
        ar[func(constructor)]++;
    for(int i = 1; i<=10000; i++)
    {
        if (ar[i] == 0)
            cout << i << endl;
    }
}