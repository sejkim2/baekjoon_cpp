#include <iostream>
#include <algorithm>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'

int N, S;
vector<int> v;

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int p1 = 0, p2 = 0;
    int ans = 0x7FFFFFFF; // 수정: 더 큰 초기값 사용
    int total = 0;
    while (p2 < N || p1 <= p2) // 수정: 루프 종료 조건 수정
    {
        if (total >= S)
        {
            ans = min(ans, p2 - p1);
            total -= v[p1];
            p1++;
        }
        else if (p2 < N) // 수정: p2가 N보다 작은 경우에만 total을 증가시키도록 수정
        {
            total += v[p2];
            p2++;
        }
        else
        {
            break; // 수정: 루프 종료
        }
    }
    if (ans == 0x7FFFFFFF) // 추가: S를 만족하는 부분 수열이 없는 경우
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}