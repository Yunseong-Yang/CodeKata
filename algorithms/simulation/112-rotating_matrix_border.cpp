// Date: 2026-05-07
// Source: https://school.programmers.co.kr/learn/courses/30/lessons/77485

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns));
    
    int n = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            board[i][j] = n;
            n++;
        }
    }
    
    for (int i = 0; i < queries.size(); ++i)
    {
        int r1 = queries[i][0] - 1;
        int c1 = queries[i][1] - 1;
        int r2 = queries[i][2] - 1;
        int c2 = queries[i][3] - 1;
        
        int temp = board[r1][c1];
        int min_val = temp;
        
        for (int i = r1; i < r2; ++i)
        {
            board[i][c1] = board[i + 1][c1];
            min_val = min(min_val, board[i][c1]);
        }
        
        for (int i = c1; i < c2; ++i)
        {
            board[r2][i] = board[r2][i + 1];
            min_val = min(min_val, board[r2][i]);
        }
        
        for (int i = r2; i > r1; --i)
        {
            board[i][c2] = board[i - 1][c2];
            min_val = min(min_val, board[i][c2]);
        }
        
        for (int i = c2; i > c1; --i)
        {
            board[r1][i] = board[r1][i - 1];
            min_val = min(min_val, board[r1][i]);
        }
        
        board[r1][c1 + 1] = temp;
        
        answer.push_back(min_val);
    }
    
    return answer;
}