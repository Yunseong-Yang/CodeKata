// Date: 2026-07-29
// BOJ 4485

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node(int cost, int row, int col)
        : cost{ cost }, row{ row }, col{ col } { }

    int cost;
    int row;
    int col;

    bool operator<(const Node& other) const
    {
        return cost > other.cost;
    }
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    int n;
    int tc = 1;

    while (cin >> n)
    {
        if (n == 0) break;

        vector<vector<int>> arr(n, vector<int>(n));
        vector<vector<int>> dist(n, vector<int>(n, 9999999));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        priority_queue<Node> pq;

        dist[0][0] = arr[0][0];
        pq.push(Node(arr[0][0], 0, 0));

        while (!pq.empty())
        {
            Node cur = pq.top();
            pq.pop();

            int cur_cost = cur.cost;
            int row = cur.row;
            int col = cur.col;

            // 이미 처리된 적이 있는 노드라면 무시
            if (cur_cost > dist[row][col]) continue;

            // 목적지에 도착했다면 종료
            if (row == n - 1 && col == n - 1) break;

            for (int i = 0; i < 4; ++i)
            {
                int nrow = row + dy[i];
                int ncol = col + dx[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n)
                {
                    // 다음 칸으로 갈 때의 비용 처리
                    int next_cost = cur_cost + arr[nrow][ncol];

                    // 기존에 알려진 다음 칸까지의 비용보다 지금 구한 비용이 더 저렴하다면 갱신
                    if (next_cost < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = next_cost;
                        pq.push(Node(next_cost, nrow, ncol));
                    }
                }
            }
        }

        cout << "Problem " << tc << ": " << dist[n - 1][n - 1] << "\n";
        tc++;
    }

    return 0;
}