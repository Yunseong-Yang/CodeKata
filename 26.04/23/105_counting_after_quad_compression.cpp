// https://school.programmers.co.kr/learn/courses/30/lessons/68936

#include <string>
#include <vector>

using namespace std;

vector<int> cnt(2, 0);

void check(const vector<vector<int>>& arr, int row, int col, int length)
{
    if (length == 1)
    {
        arr[row][col] == 0 ? cnt[0]++ : cnt[1]++;
        return;
    }
    
    int n = arr[row][col];
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (arr[row + i][col + j] != n)
            {
                check(arr, row, col, length / 2);
                check(arr, row, col + length / 2, length / 2);
                check(arr, row + length / 2, col, length / 2);
                check(arr, row + length / 2, col + length / 2, length / 2);
                return;
            }
        }
    }
    
    n == 0 ? cnt[0]++ : cnt[1]++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int length = arr.size();
    
    check(arr, 0, 0, length);
    
    return cnt;
}
