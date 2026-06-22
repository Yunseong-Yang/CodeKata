// Date: 2026-06-21
// BOJ 4179

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> v;
vector<vector<int>> visited1;
vector<vector<int>> visited2;
pair<int, int> start;
vector<pair<int, int>> fire;

int r, c;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs()
{
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    q1.push(start);

    visited1.assign(r, vector<int>(c, 0));
    visited1[start.first][start.second] = 1;

    visited2.assign(r, vector<int>(c, 0));
    for (pair<int, int> f : fire)
    {
        q2.push(f);
        visited2[f.first][f.second] = 1;
    }

    int cnt = 0;

    while (!q1.empty())
    {
        cnt++;

        int size2 = q2.size();
        while (size2--)
        {
            int row2 = q2.front().first;
            int col2 = q2.front().second;
            q2.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow2 = row2 + dy[i];
                int ncol2 = col2 + dx[i];

                if (nrow2 < 0 || nrow2 >= r || ncol2 < 0 || ncol2 >= c)
                    continue;
                if (visited2[nrow2][ncol2] || v[nrow2][ncol2] == '#')
                    continue;

                visited2[nrow2][ncol2] = 1;
                v[nrow2][ncol2] = 'F';
                q2.push({ nrow2, ncol2 });
            }
        }

        int size1 = q1.size();
        while (size1--)
        {
            int row1 = q1.front().first;
            int col1 = q1.front().second;
            q1.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow1 = row1 + dy[i];
                int ncol1 = col1 + dx[i];

                if (nrow1 == -1 || nrow1 == r || ncol1 == -1 || ncol1 == c)
                {
                    return cnt;
                }

                if (visited1[nrow1][ncol1] || v[nrow1][ncol1] == '#' || v[nrow1][ncol1] == 'F')
                    continue;

                q1.push({ nrow1, ncol1 });
                visited1[nrow1][ncol1] = 1;
            }
        }
    }

    return -1;
}

int main()
{
    cin >> r >> c;
    v.resize(r);

    for (int i = 0; i < r; i++)
    {
        cin >> v[i];
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 'J')
            {
                start = { i, j };
            }
            else if (v[i][j] == 'F')
            {
                fire.push_back({ i, j });
            }
        }
    }

    int n = bfs();
    if (n == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << n << "\n";
    }

    return 0;
}