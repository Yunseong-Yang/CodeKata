// Date: 2026-07-30
// BOJ 1956

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    int INF = 9999999;
    vector<vector<int>> dist(v, vector<int>(v, INF));

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = c;
    }

    for (int k = 0; k < v; ++k)
    {
        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < v; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int min_val = INF;
    for (int i = 0; i < v; ++i)
    {
        if (dist[i][i] < min_val)
        {
            min_val = dist[i][i];
        }
    }

    if (min_val == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << min_val << "\n";
    }

    return 0;
}