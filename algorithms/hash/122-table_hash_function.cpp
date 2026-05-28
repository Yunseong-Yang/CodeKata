// Date: 2026-05-28
// https://school.programmers.co.kr/learn/courses/30/lessons/147354

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int s_col;

int cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[s_col - 1] == b[s_col - 1])
    {
        return a[0] > b[0];
    }
    else
    {
        return a[s_col - 1] < b[s_col - 1];
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    s_col = col;
    
    sort(data.begin(), data.end(), cmp);
    
    vector<int> xor_list;
    
    for (int i = row_begin; i <= row_end; i++)
    {
        int sum = 0;
        for (int n : data[i - 1])
        {
            sum += (n % i);
        }
        xor_list.push_back(sum);
    }
    
    answer = xor_list[0];
    for (int i = 1; i < xor_list.size(); i++)
    {
        answer = answer ^ xor_list[i];
    }
    
    return answer;
}