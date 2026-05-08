// Date: 2026-05-08
// Source: https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int BFS(int n, const vector<vector<int>>& arr)
{
    queue<int> q;
    q.push(n);
    vector<bool> visited(arr.size());
    visited[n] = true;
    int cnt = 1;

    while(!q.empty())
    {
        int search = q.front();
        q.pop();
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[search][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }

    return cnt;
}


int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < wires.size(); ++i)
    {
        int a = wires[i][0] - 1;
        int b = wires[i][1] - 1;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    int min_val = 100;
    for (int i = 0; i < wires.size(); ++i)
    {
        int a = wires[i][0] - 1;
        int b = wires[i][1] - 1;

        arr[a][b] = 0;
        arr[b][a] = 0;

        int n1 = BFS(a, arr);
        int n2 = BFS(b, arr);

        if (min_val > abs(n1 - n2))
        {
            min_val = abs(n1 - n2);
        }

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    return min_val;
}