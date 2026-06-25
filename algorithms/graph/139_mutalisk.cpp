// BFS 방식
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int damage[6][3] = {
    { 9, 3, 1 }, { 9, 1, 3 }, { 3, 9, 1 },
    { 3, 1, 9 }, { 1, 9, 3 }, { 1, 3, 9 }
};
int arr[61][61][61];

struct Data
{
    int hp[3];

    Data()
    {
        hp[0] = 0; hp[1] = 0; hp[2] = 0;
    }
    Data(int a1, int a2 = 0, int a3 = 0)
    {
        hp[0] = a1; hp[1] = a2; hp[2] = a3;
    }
};

void bfs(Data data)
{
    queue<pair<Data, int>> q;
    q.push({ data, 0 });

    arr[data.hp[0]][data.hp[1]][data.hp[2]] = 1;

    while (!q.empty())
    {
        Data d = q.front().first;
        int val = q.front().second;
        q.pop();

        if (d.hp[0] == 0 && d.hp[1] == 0 && d.hp[2] == 0)
        {
            cout << val << "\n";
            return;
        }

        for (int i = 0; i < 6; ++i)
        {
            int d1 = max(0, d.hp[0] - damage[i][0]);
            int d2 = max(0, d.hp[1] - damage[i][1]);
            int d3 = max(0, d.hp[2] - damage[i][2]);

            if (arr[d1][d2][d3] == 0)
            {
                arr[d1][d2][d3] = 1;
                q.push({ Data(d1, d2, d3), val + 1 });
            }
        }
    }
}

int main()
{
    cin >> n;
    Data data{};
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        data.hp[i] = a;
    }

    bfs(data);

    return 0;
}

// 백트래킹으로 해보기
/*
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int damage[6][3] = {
    { 9, 3, 1 }, { 9, 1, 3 }, { 3, 9, 1 },
    { 3, 1, 9 }, { 1, 9, 3 }, { 1, 3, 9 }
};

int dp[61][61][61];
int min_val = 999;

void dfs(int h1, int h2, int h3, int cnt)
{
    h1 = max(0, h1);
    h2 = max(0, h2);
    h3 = max(0, h3);

    if (h1 == 0 && h2 == 0 && h3 == 0)
    {
        if (cnt < min_val) min_val = cnt;
        return;
    }

    if (cnt >= min_val) return;

    if (dp[h1][h2][h3] != 0 && dp[h1][h2][h3] <= cnt) return;

    dp[h1][h2][h3] = cnt;

    for (int i = 0; i < 6; ++i)
    {
        dfs(h1 - damage[i][0], h2 - damage[i][1], h3 - damage[i][2], cnt + 1);
    }
}

int main()
{
    cin >> n;
    int hp[3] = { 0, 0, 0 };
    for (int i = 0; i < n; ++i)
    {
        cin >> hp[i];
    }

    dfs(hp[0], hp[1], hp[2], 0);

    cout << min_val << "\n";

    return 0;
}
*/