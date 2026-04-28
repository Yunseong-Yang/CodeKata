// https://school.programmers.co.kr/learn/courses/30/lessons/68645

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> arr;
    
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(vector<int>(i + 1));
    }
    int state = 0;
    int row = -1;
    int col = 0;
    int cnt = 1;
    for (int i = n; i > 0; --i)
    {
        if (state == 0)
        {
            for (int j = 0; j < i; ++j)
            {
                row++;
                arr[row][col] = cnt;
                cnt++;
            }
        }
        else if (state == 1)
        {
            for (int j = 0; j < i; ++j)
            {
                col++;
                arr[row][col] = cnt;
                cnt++;
            }
        }
        else if (state == 2)
        {
            for (int j = 0; j < i; ++j)
            {
                col--;
                row--;
                arr[row][col] = cnt;
                cnt++;
            }
        }
        state++;
        state %= 3;
    }
    
    for (vector<int> v: arr)
    {
        for (int n : v)
        {
            answer.push_back(n);
        }
    }
    
    return answer;
}
