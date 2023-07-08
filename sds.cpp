#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define endl '\n'
using namespace std;

#include <queue>
#include <algorithm>
char Map[502][502];
int visited[502][502];
int T, N, M;
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
int check_row, check_col;

void init_visited()
{
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
            visited[i][j] = 0;
    }
}

int bfs(int row, int col, char find_color)
{
    queue<pair<int, int> > q;
    init_visited();

    q.push(make_pair(row, col));

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (Map[r][c] == find_color || (r == N && c == M))
        {
            check_row = r;
            check_col = c;
            return (visited[r][c]);
        }
        for(int i = 0; i<4; i++)
        {
            int next_r = r + dir_x[i];
            int next_c = c + dir_y[i];
            if (next_r < 1 || next_r > N || next_c < 1 || next_c > M)
                continue;
            if (Map[next_r][next_c] != 'X' && visited[next_r][next_c] == 0)
            {
                visited[next_r][next_c] = visited[r][c] + 1;
                q.push(make_pair(next_r, next_c));
            }
        }
    }
    return (-1);
}

int main()
{
    cin >> T;
    for(int i = 1; i<=T; i++)
    {
        cin >> N >> M;
        int t1, t2, t3, t4, t5;
        for(int i = 1; i<=N; i++)
        {
            for(int j = 1; j<=M; j++)
                cin >> Map[i][j];
        }
        t1 = bfs(1, 1, 'R');
        if (t1 == -1)
        {
            cout << "#" << i << " -1" << endl;
            continue;
        }
        t2 = bfs(check_row, check_col, '.');
        if (t2 == -1)
        {
            cout << "#" << i << " -1" << endl;
            continue;
        }
        t3 = bfs(check_row, check_col, 'B');
        if (t3 == -1)
        {
            cout << "#" << i << " -1" << endl;
            continue;
        }
        t4 = bfs(check_row, check_col, '.');
        if (t4 == -1)
        {
            cout << "#" << i << " -1" << endl;
            continue;
        }
        t5 = bfs(check_row, check_col, 'N');
        if (t5 == -1)
        {
            cout << "#" << i << " -1" << endl;
            continue;
        }
        cout << "#" << i << " " << t1 + t2 + t3 + t4 + t5<< endl;
    }
}