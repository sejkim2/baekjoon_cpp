#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

string str;
long long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    string num = "";
    cin >> str;
    result = 0;

    int i = 0;
    int flag = 0;
    while (i <= str.size())
    {
        if (str[i] == '-' || str[i] == '+')
        {
            if (flag == 1)
                result -= stoi(num);
            else
                result += stoi(num);
            num = "";
            if (str[i] == '-')
                flag = 1;
        }
        else
            num += str[i];
        i++;
    }
    if (flag == 1)
        result -= stoi(num);
    else
        result += stoi(num);
    cout << result;
}
