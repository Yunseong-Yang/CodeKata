// Date: 2026-08-14
// BOJ 14497

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int row1, col1, row2, col2;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<char>> arr;

int bfs()
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> convert;
    vector<vector<char>> visited(n, vector<char>(m));

    q.push({ row1 - 1, col1 - 1 });
    visited[row1 - 1][col1 - 1] = 1;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (arr[row][col] == '1')
        {
            convert.push_back({ row, col });
            continue;
        }

        if (arr[row][col] == '#')
        {
            return 1;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + dy[i];
            int ncol = col + dx[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
            {
                q.push({ nrow, ncol });
                visited[nrow][ncol] = 1;
            }
        }
    }

    for (const pair<int, int>& p : convert)
    {
        arr[p.first][p.second] = '0';
    }

    return 0;
}

int main(void)
{
    cin >> n >> m;
    cin >> row1 >> col1 >> row2 >> col2;

    arr.resize(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char a;
            cin >> a;
            arr[i][j] = a;
        }
    }

    int cnt = 0;
    while (true)
    {
        cnt++;
        int flag = 0;

        flag = bfs();

        if (flag)
        {
            cout << cnt;
            return 0;
        }
    }

    return 0;
}
