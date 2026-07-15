// Date: 2026-07-15
// BOJ 13913

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

vector<int> visited(100001, 0);
vector<int> v(100001, 0);

void bfs()
{
    visited[n] = 1;
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)
        {
            cout << visited[cur] - 1 << "\n";
            int m = cur;
            vector<int> temp;
            while (m != n)
            {
                temp.push_back(m);
                m = v[m];
            }
            temp.push_back(m);

            reverse(temp.begin(), temp.end());

            for (int l : temp)
            {
                cout << l << " ";
            }

            return;
        }

        int pos[3] = { cur + 1, cur - 1, cur * 2 };

        for (int i = 0; i < 3; ++i)
        {
            if (pos[i] >= 0 && pos[i] <= 100000 && !visited[pos[i]])
            {
                q.push(pos[i]);
                visited[pos[i]] = visited[cur] + 1;
                v[pos[i]] = cur;
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    bfs();

    return 0;
}