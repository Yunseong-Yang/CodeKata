// Date: 2026-07-22
// BOJ 15683

#include <iostream>
#include <vector>

using namespace std;

struct point
{
    point(int num, int row, int col)
        : num{ num }, row{ row }, col{ col } {}

    int num;
    int row;
    int col;
};

int n, m;
int min_val = 999999;
vector<vector<int>> arr;
vector<point> v;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void check(vector<vector<int>>& temp, int row, int col, int dir)
{
    dir %= 4;

    while (true)
    {
        row += dx[dir];
        col += dy[dir];

        if (row < 0 || col < 0 || row >= n || col >= m || temp[row][col] == 6)
        {
            break;
        }

        if (temp[row][col] == 0)
        {
            temp[row][col] = -1;
        }
    }
}

void dfs(int index, vector<vector<int>> cur)
{
    if (index == v.size())
    {
        int hide = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (cur[i][j] == 0)
                {
                    hide++;
                }
            }
        }

        if (hide < min_val)
        {
            min_val = hide;
        }

        return;
    }

    int row = v[index].row;
    int col = v[index].col;
    int num = v[index].num;

    for (int i = 0; i < 4; ++i)
    {
        vector<vector<int>> temp = cur;

        if (num == 1)
        {
            check(temp, row, col, i);
        }
        else if (num == 2)
        {
            check(temp, row, col, i);
            check(temp, row, col, i + 2);
        }
        else if (num == 3)
        {
            check(temp, row, col, i);
            check(temp, row, col, i + 1);
        }
        else if (num == 4)
        {
            check(temp, row, col, i);
            check(temp, row, col, i + 1);
            check(temp, row, col, i + 2);
        }
        else if (num == 5)
        {
            check(temp, row, col, i);
            check(temp, row, col, i + 1);
            check(temp, row, col, i + 2);
            check(temp, row, col, i + 3);
        }

        dfs(index + 1, temp);
    }
}

int main()
{
    cin >> n >> m;
    arr.assign(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int a;
            cin >> a;
            arr[i][j] = a;

            if (a != 0 && a != 6)
            {
                v.push_back(point(a, i, j));
            }
        }
    }

    dfs(0, arr);

    cout << min_val;

    return 0;
}