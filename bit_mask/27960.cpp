#include <iostream>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false)
#define endl '\n'
using namespace std;

int sA, sB, sC;

int main()
{
    cin >> sA >> sB;
    sC = sA ^ sB;
    cout << sC;
}