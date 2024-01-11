#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'
using namespace std;

int A, B, C;

int main(void)
{
    int result1, result2;
    cin >> A >> B >> C;
    result1 = A ^ B;
    result2 = A;
    if (C % 2 == 0)
        cout << result2;
    else
        cout << result1;
}