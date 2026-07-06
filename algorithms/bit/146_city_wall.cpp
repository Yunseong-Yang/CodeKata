#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, max_val1, max_val2;
vector<vector<int>> arr;
vector<vector<int>> visited;
vector<int> room_size(2501);

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void bfs(int r, int c, int id)
{
    queue<pair<int, int>> q;
    q.push({ r, c });

    visited[r][c] = id;
    int val = 0;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        val++;

        for (int i = 0; i < 4; ++i)
        {
            if ((arr[row][col] & (1 << i)) == 0)
            {
                int nrow = row + dy[i];
                int ncol = col + dx[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
                {
                    q.push({ nrow, ncol });
                    visited[nrow][ncol] = id;
                }
            }
        }
    }

    room_size[id] = val;
    max_val1 = max(max_val1, val);
}

int main()
{
    cin >> m >> n;

    arr.assign(n, vector<int>(m));
    visited.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int id = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j])
            {
                bfs(i, j, id);
                id++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if ((arr[i][j] & (1 << k)) != 0)
                {
                    int nrow = i + dy[k];
                    int ncol = j + dx[k];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                    {
                        int room = visited[i][j];
                        int next_room = visited[nrow][ncol];

                        if (room != next_room)
                        {
                            max_val2 = max(max_val2, room_size[room] + room_size[next_room]);
                        }
                    }
                }
            }
        }
    }

    cout << id - 1 << "\n";
    cout << max_val1 << "\n";
    cout << max_val2 << "\n";

    return 0;
}