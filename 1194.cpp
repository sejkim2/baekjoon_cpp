#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <queue>

int n, m;
int move_row[4] = {1, -1, 0, 0};
int move_col[4] = {0, 0, 1, -1};
char maze[51][51];
int keys[6];
int visited[51][51];

void init_visited()
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
            visited[i][j] = 0;
    }
}

int bfs(int row, int col)
{
    int walk = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    
    while (!q.empty())
    {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        char ch = maze[cur_row][cur_col];

        if (ch >= 'a' && ch <= 'f')
        {
            keys[ch - 'a'] += 1;
            init_visited();
        }
        else if (ch == '1')
            return (walk);
        visited[cur_row][cur_col] = 1;
        walk++;

        for(int i = 0; i<4; i++)
        {
            int next_row = cur_row + move_row[i];
            int next_col = cur_col + move_col[i];
            char next_ch = maze[next_row][next_col];

            if (next_row > n || next_row < 1 || next_col > m || next_col < 1)
                continue;
            if (next_ch == '#' || visited[next_row][next_col] == 1)
                continue;
            if (next_ch >= 'A' && next_ch <= 'F')
            {
                if (keys[ch - 'A'] < 1)
                    continue;
            }
            q.push(make_pair(next_row, next_col));
        }
    }
    return (-1);
}

int main()
{
    int start_row, start_col;
    int walk = -1;
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            char ch;
            cin >> ch;
            maze[i][j] = ch;
            if (ch == '0')
            {
                start_row = i;
                start_col = j;
            }
        }
    }

    walk = bfs(start_row, start_col);
    cout << walk;
}