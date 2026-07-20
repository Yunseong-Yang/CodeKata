// Date: 2026-07-15
// BOJ 17071

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

// 홀/짝 시간대 구분 -> 홀/짝수 초에 도착한 위치는 되돌아오려면 홀/짝수 초만 가능
// 특정 위치에 어느 초만큼 도착했는지를 나타냄
vector<vector<int>> visited(2, vector<int>(500001, -1));

void bfs()
{
    visited[0][n] = 0;
    queue<pair<int, int>> q;
    q.push({ n, 0 });

    // 갈 수 있는 모든 시간 구해놓기
    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (time > 500000) break;

        int pos[3] = { cur + 1, cur - 1, cur * 2 };

        for (int i = 0; i < 3; ++i)
        {
            if (pos[i] >= 0 && pos[i] <= 500000 && visited[(time + 1) % 2][pos[i]] == -1)
            {
                q.push({ pos[i], time + 1 });
                visited[(time + 1) % 2][pos[i]] = time + 1;
            }
        }
    }

    int total = k;

    for (int i = 0; ; ++i)
    {
        total += i;

        if (total > 500000)
        {
            break;
        }

        // 수빈이가 동생의 위치에 같은 홀짝으로 해당 시간 이하에 도착한 적이 있다면
        if (visited[i % 2][total] != -1 && visited[i % 2][total] <= i)
        {
            cout << i;
            return;
        }
    }

    cout << -1;
}

int main()
{
    cin >> n >> k;
    bfs();

    return 0;
}