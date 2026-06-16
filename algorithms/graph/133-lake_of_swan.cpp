// Date: 2026-06-16
// BOJ 3197

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int r, c;
int day = 0;
vector<vector<char>> v;
vector<pair<int, int>> swan;
vector<vector<int>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs()
{
    queue<pair<int, int>> q;
    visited.assign(r, vector<int>(c, 0));

    q.push(swan[0]);
    visited[swan[0].first][swan[0].second] = 1;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == swan[1].first && col == swan[1].second)
        {
            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + dy[i];
            int ncol = col + dx[i];

            if (!(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c)) continue;

            if ((v[nrow][ncol] == '.' || v[nrow][ncol] == 'L') && !visited[nrow][ncol])
            {
                q.push({ nrow, ncol });
                visited[nrow][ncol] = 1;
            }
        }
    }

    return false;
}

void melt()
{
    vector<pair<int, int>> to_water;

    for (int i = 0; i < r; ++i) 
    {
        for (int j = 0; j < c; ++j) 
        {
            if (v[i][j] == 'X') 
            {
                bool near = false;

                for (int k = 0; k < 4; ++k) 
                {
                    int ni = i + dy[k];
                    int nj = j + dx[k];

                    if (ni >= 0 && ni < r && nj >= 0 && nj < c) 
                    {
                        if (v[ni][nj] == '.' || v[ni][nj] == 'L') 
                        {
                            near = true;
                            break;
                        }
                    }
                }

                if (near) 
                {
                    to_water.push_back({ i, j });
                }
            }
        }
    }

    for (pair<int, int> w : to_water) 
    {
        v[w.first][w.second] = '.';
    }
}

int main() {
    cin >> r >> c;
    v.resize(r);

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            char ch;
            cin >> ch;
            v[i].push_back(ch);

            if (ch == 'L')
            {
                swan.push_back({ i, j });
            }
        }
    }

    while (!bfs())
    {
        day++;
        melt();
    }

    cout << day;

    return 0;
}

// 시간 초과로 인한 정답
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int r, c;
//int day = 0;
//vector<string> v;
//vector<pair<int, int>> swan;
//vector<vector<int>> visited;
//
//queue<pair<int, int>> swan_q, swan_next_q;
//queue<pair<int, int>> water_q, water_next_q;
//
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//bool bfs()
//{
//    while (!swan_q.empty())
//    {
//        int row = swan_q.front().first;
//        int col = swan_q.front().second;
//        swan_q.pop();
//
//        if (row == swan[1].first && col == swan[1].second)
//        {
//            return true;
//        }
//
//        for (int i = 0; i < 4; ++i)
//        {
//            int nrow = row + dy[i];
//            int ncol = col + dx[i];
//
//            if (!(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c)) continue;
//
//            if (!visited[nrow][ncol])
//            {
//                visited[nrow][ncol] = 1;
//
//                if (v[nrow][ncol] == '.' || v[nrow][ncol] == 'L')
//                {
//                    swan_q.push({ nrow, ncol });
//                }
//                else if (v[nrow][ncol] == 'X')
//                {
//                    swan_next_q.push({ nrow, ncol });
//                }
//            }
//        }
//    }
//    return false;
//}
//
//void melt()
//{
//    while (!water_q.empty())
//    {
//        int row = water_q.front().first;
//        int col = water_q.front().second;
//        water_q.pop();
//
//        for (int i = 0; i < 4; ++i)
//        {
//            int nrow = row + dy[i];
//            int ncol = col + dx[i];
//
//            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c)
//            {
//                if (v[nrow][ncol] == 'X')
//                {
//                    v[nrow][ncol] = '.';
//                    water_next_q.push({ nrow, ncol });
//                }
//            }
//        }
//    }
//}
//
//int main() {
//
//    cin >> r >> c;
//    v.resize(r);
//    visited.assign(r, vector<int>(c, 0));
//
//    for (int i = 0; i < r; ++i)
//    {
//        cin >> v[i];
//        for (int j = 0; j < c; ++j)
//        {
//            if (v[i][j] == 'L')
//            {
//                swan.push_back({ i, j });
//            }
//            if (v[i][j] == '.' || v[i][j] == 'L')
//            {
//                water_q.push({ i, j });
//            }
//        }
//    }
//
//    swan_q.push(swan[0]);
//    visited[swan[0].first][swan[0].second] = 1;
//
//    while (!bfs())
//    {
//        melt();
//
//        swan_q = swan_next_q;
//        while (!swan_next_q.empty()) swan_next_q.pop();
//
//        water_q = water_next_q;
//        while (!water_next_q.empty()) water_next_q.pop();
//
//        day++;
//    }
//
//    cout << day << "\n";
//
//    return 0;
//}