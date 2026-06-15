// Date: 2026-06-15
// BOJ 14502

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int safe = 0;
int zero = 0;
vector<vector<int>> v;
vector<pair<int, int>> candidate;
vector<pair<int, int>> selected;
vector<pair<int, int>> virus;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void bfs(vector<vector<int>>& arr)
{
    queue<pair<int, int>> q;
    
    for (pair<int, int> vir : virus)
    {
        q.push(vir);
    }

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + dy[i];
            int ncol = col + dx[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && arr[nrow][ncol] == 0)
            {
                q.push({ nrow, ncol });
                arr[nrow][ncol] = 2;
                zero--;
            }
        }
    }
}

void makeWall(int index, int depth)
{
    if (depth == 3)
    {
        vector<vector<int>> arr(v.begin(), v.end());
        int copy_zero = zero;
        for (int i = 0; i < 3; ++i)
        {
            int a = selected[i].first;
            int b = selected[i].second;
            zero--;
            arr[a][b] = 1;
        }

        bfs(arr);
        if (zero > safe)
        {
            safe = zero;
        }
        zero = copy_zero;
        return;
    }

    for (int i = index; i < candidate.size(); ++i) 
    {
        selected.push_back(candidate[i]);
        makeWall(i + 1, depth + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int a;
            cin >> a;
            v[i].push_back(a);

            if (v[i][j] == 0)
            {
                zero++;
                candidate.push_back({ i, j });
            }
            else if (v[i][j] == 2)
            {
                virus.push_back({ i, j });
            }
        }
    }

    makeWall(0, 0);

    cout << safe;

    return 0;
}