#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <queue>

struct Data {
    int row;
    int col;
    int key;
};
int n, m;
int move_row[4] = {1, -1, 0, 0};
int move_col[4] = {0, 0, 1, -1};
char maze[51][51];
int visited[51][51][1<<6];

int bfs(int row, int col)
{
    queue<pair<int, Data> > q;   //walk, {row, col, key}
    Data d;
    d.row = row;
    d.col = col;
    d.key = 0;
    q.push(make_pair(0, d));
    visited[row][col][d.key] = 1;
    
    while (!q.empty())
    {
        int cur_walk = q.front().first;
        Data cur_d = q.front().second;
        int cur_row = cur_d.row;
        int cur_col = cur_d.col;
        int cur_key = cur_d.key;
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            int next_row = cur_row + move_row[i];
            int next_col = cur_col + move_col[i];
            char next_ch = maze[next_row][next_col];

            if (next_row > n || next_row < 1 || next_col > m || next_col < 1)
                continue;
            
            if (next_ch == '1')
                return (cur_walk + 1);
            else if (next_ch == '#')
                continue;
            else if (next_ch >= 'A' && next_ch <= 'F')
            {
                int k = next_ch - 'A';
                if ((cur_key & (1 << k)) != 0 && !visited[next_row][next_col][cur_key])
                {
                    visited[next_row][next_col][cur_key] = 1;
                    Data tmp;
                    tmp.row = next_row;
                    tmp.col = next_col;
                    tmp.key = cur_key;
                    q.push(make_pair(cur_walk + 1, tmp));
                }
            }
            else if (next_ch >= 'a' && next_ch <= 'f')
            {
                int k = next_ch - 'a';
                int next_key = cur_key | (1 << k);
                if (!visited[next_row][next_col][next_key])
                {
                    visited[next_row][next_col][next_key] = 1;
                    Data tmp;
                    tmp.row = next_row;
                    tmp.col = next_col;
                    tmp.key = next_key;
                    q.push(make_pair(cur_walk + 1, tmp));
                }
            }
            else    // '.' or '0'
            {
                if (!visited[next_row][next_col][cur_key])
                {
                    visited[next_row][next_col][cur_key] = 1;
                    Data tmp;
                    tmp.row = next_row;
                    tmp.col = next_col;
                    tmp.key = cur_key;
                    q.push(make_pair(cur_walk + 1, tmp));
                }
            }
        }
    }
    return (-1);
}

int main()
{
    int start_row, start_col;
    int ans = -1;
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

    ans = bfs(start_row, start_col);

    cout << ans;
}