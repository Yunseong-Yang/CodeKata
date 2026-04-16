// https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_VALUE 2147483647

using namespace std;

int BFS(int value, int y, int n)
{
    queue<pair<int, int>> q;
    q.push({value, 1});
    vector<bool> visited(y + 1, false);
    while(!q.empty())
    {
        int num = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (num == y)
        {
            return depth;
        }
        else
        {
            if (num + n <= y && !visited[num + n]) 
            {
                visited[num + n] = true;
                q.push({num + n, depth + 1});
            }

            if (num * 2 <= y && !visited[num * 2]) 
            {
                visited[num * 2] = true;
                q.push({num * 2, depth + 1});
            }

            if (num * 3 <= y && !visited[num * 3]) 
            {
                visited[num * 3] = true;
                q.push({num * 3, depth + 1});
            }
        }
    }
    
    return MAX_VALUE;
}

int solution(int x, int y, int n) {
    if (x == y)
    {
        return 0;
    }
    
    int answer = 0;
    vector<int> v(3);
    
    v[0] = BFS(x + n, y, n);
    v[1] = BFS(x * 2, y, n);
    v[2] = BFS(x * 3, y, n);
    
    if (v[0] == MAX_VALUE && v[1] == MAX_VALUE && v[2] == MAX_VALUE)
    {
        return -1;
    }
    else
    {
        return *min_element(v.begin(), v.end());
    }
}
