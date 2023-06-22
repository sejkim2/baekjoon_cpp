#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define endl '\n'
using namespace std;

#include <string.h>
#include <stack>
#include <queue>

string str;
stack<char> s;
queue<char> q;

int main()
{
    int i = 0;
 
    getline(cin, str, '\n');
    while (str[i])
    {
        if (str[i] == '<')
        {
            while (1)
            {
                q.push(str[i]);
                if (str[i] == '>')
                {
                    i++;
                    break;
                }
                i++;
            }
            while (!q.empty())
            {
                cout << q.front();
                q.pop();
            }
        }
        else
        {
            while (1)
            {
                if (str[i] == ' ' || str[i] == '<' || str[i] == '\0')
                    break;
                s.push(str[i]);
                i++;
            }
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
        }
        if (str[i] == ' ')
            cout << str[i++];
    }
}