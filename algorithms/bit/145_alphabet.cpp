// Date: 2026-07-03
// BOJ 1987

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<char>> arr;
int max_cnt = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int row, int col, int bit, int cnt)
{
    max_cnt = max(max_cnt, cnt);

    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + dy[i];
        int ncol = col + dx[i];

        if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c)
        {
            int val = arr[nrow][ncol] - 'A';

            if ((bit & (1 << val)) == 0)
            {
                dfs(nrow, ncol, bit | (1 << val), cnt + 1);
            }
        }
    }
}

int main()
{
    cin >> r >> c;

    arr.assign(r, vector<char>(c));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0, (1 << (arr[0][0] - 'A')), 1);

    cout << max_cnt;

    return 0;
}