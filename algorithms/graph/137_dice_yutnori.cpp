// Date: 2026-06-22
// BOJ 17825

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> dice;
int horse[4] = { 0, 0, 0, 0 };
int max_score = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int board[33] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0, // 0 ~ 21
    13, 16, 19, // 10, 22 ~ 24
    22, 24, // 20, 25 ~ 26
    28, 27, 26, // 30, 27 ~ 29
    25, 30, 35 // 25, 30 ~ 32
};

int red_graph[33];
int blue_graph[33];

void dfs(int turn, int score)
{
    if (turn == 10)
    {
        if (max_score < score)
        {
            max_score = score;       
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (horse[i] == 21) continue;

        // 1. 현재 말이 블루 칸에 있으면, 이동 경로를 블루 그래프로 재설정 한다.
        int cur = horse[i];
        int move_cnt = dice[turn];

        if (blue_graph[cur] != 0)
        {
            cur = blue_graph[cur];
            move_cnt--;
        }

        // 2. 설정된 이동 경로에 따라서 이동 위치를 계산 한다.
        while (move_cnt > 0)
        {
            cur = red_graph[cur];
            move_cnt--;
            if (cur == 21) break;
        }
        // 3. 만약 이동한 곳이 다른 말과 겹친다면, break
        bool can_move = true;
        if (cur != 21)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (i != j && cur == horse[j])
                {
                    can_move = false;
                    break;
                }
            }
        }

        // 4. 이후 실제로 움직인다. 이때, 현재 움직이는 말이 최대가 아닐 수 있으므로 롤백을 해주면서 백트래킹을 한다.

        if (can_move)
        {
            int prev = horse[i];
            horse[i] = cur;

            dfs(turn + 1, score + board[cur]);
            horse[i] = prev;
        }
    }
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        int a;
        cin >> a;
        dice.push_back(a);
    }

    for (int i = 0; i < 33; ++i)
    {
        red_graph[i] = i + 1;
    }
    red_graph[22] = 23; red_graph[23] = 24; red_graph[24] = 30;
    red_graph[25] = 26; red_graph[26] = 30;
    red_graph[27] = 28; red_graph[28] = 29; red_graph[29] = 30;
    red_graph[30] = 31; red_graph[31] = 32; red_graph[32] = 20;

    for (int i = 0; i < 33; ++i)
    {
        blue_graph[i] = 0;
    }
    blue_graph[5] = 22; blue_graph[10] = 25; blue_graph[15] = 27;

    dfs(0, 0);

    cout << max_score << endl;

    return 0;
}