// Date: 2026-05-04
// https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

using namespace std;
vector<vector<int>> visited(101, vector<int>(101));

int BFS(const vector<string>& maps, pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    int sum = 0;
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        sum += maps[row][col] - '0';
        
        for (int i = 0; i < 4; i++)
        {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if (new_row >= 0 && new_row < maps.size() && new_col >=0 && new_col < maps[0].size())
            {
                if (maps[new_row][new_col] != 'X' && !visited[new_row][new_col])
                {
                    q.push({new_row, new_col});
                    visited[new_row][new_col] = true;
                }
            }
            
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] != 'X' && !visited[i][j])
            {
                visited[i][j] = true;
                answer.push_back(BFS(maps, {i, j}));
            }
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
