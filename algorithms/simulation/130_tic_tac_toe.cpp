// Date: 2026-06-10
// https://school.programmers.co.kr/learn/courses/30/lessons/160585

#include <string>
#include <vector>

using namespace std;

bool check(const vector<string>& board, char c)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
    
    return false;
}

int solution(vector<string> board) {
    int cnt1 = 0;
    int cnt2 = 0;
    
    for (string s : board)
    {
        for (char c : s)
        {
            if (c == 'O')
            {
                cnt1++;
            }
            else if (c == 'X')
            {
                cnt2++;
            }
        }
    }
    
    int total = cnt1 + cnt2;

    if (check(board, 'O') && check(board, 'X')) return 0;
    
    if (check(board, 'O'))
    {
        if (cnt1 - cnt2 != 1)
        {
            return 0;
        }
    }
    else if (check(board, 'X'))
    {
        if (cnt1 != cnt2)
        {
            return 0;
        }
    }
    
    if (total % 2 == 1)
    {
        if (cnt1 - cnt2 != 1)
        {
            return 0;
        }
    }
    else
    {
        if (cnt1 != cnt2)
        {
            return 0;
        }
    }
    
    return 1;
}