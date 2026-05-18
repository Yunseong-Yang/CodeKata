// Date: 2026-05-18
// https://school.programmers.co.kr/learn/courses/30/lessons/81302
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int BFS(const vector<string>& v, vector<vector<int>> visited, int r, int c)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 0});
    visited[r][c] = 1;
    
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int cur_length = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            
            if (new_row >= 0 && new_row < 5 && new_col >= 0 && new_col < 5 
                && !visited[new_row][new_col] && v[new_row][new_col] != 'X')
            {
                if (v[new_row][new_col] == 'P' && cur_length <= 1)
                {
                    return 0;
                }
                
                visited[new_row][new_col] = 1;
                q.push({{new_row, new_col}, cur_length + 1});
            }
        }
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (const vector<string>& v : places)
    {
        vector<vector<int>> visited(5, vector<int>(5));
        int result = 1;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (v[i][j] == 'P')
                {
                    result *= BFS(v, visited, i, j);
                }
            }
        }
        answer.push_back(result);
    }
    
    return answer;
}