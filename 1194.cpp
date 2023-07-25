#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <queue>

int n, m;
int move_row[4] = {1, 1, 0, 0};
int move_col[4] = {0. -1, 1, -1};
char maze[51][51];
int keys[6];
int visited[51][51];

void bfs(int row, int col)
{
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    
    while (!q.empty())
    {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        visited[cur_row][cur_col] = 1;
        char ch = maze[cur_row][cur_col];
        if (ch >= 'A' && ch <= 'F')
        {
            if (keys[ch - 'A'] < 1)
                return (0);
        }
        for(int i = 0; i<4; i++)
        {
            int next_row = cur_row + move_row[i];
            int next_col = cur_col + move_col[i];
            if (next_row > n || next_row < 1 || next_col > m || next_col < 1)
                continue;
            
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            char ch;
            cin >> ch;
            maze[i][j] = ch;
            if (ch >= 'A' && ch <= 'F')
                keys[ch - 'A'] += 1;
        }
    }


}