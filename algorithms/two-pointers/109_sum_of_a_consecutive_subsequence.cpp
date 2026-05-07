// Date: 2026-04-29
// https://school.programmers.co.kr/learn/courses/30/lessons/178870

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second - a.first != b.second - b.first)
    {
        return a.second - a.first < b.second - b.first;
    }
    else
    {
        return a.first < b.first;
    }
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> answer_list;
    
    int start = 0;
    int end = 0;
    int sum = sequence[0];
    while (start != sequence.size() && end != sequence.size())
    {
        if (sum == k)
        {
            answer_list.push_back({start, end});
            end++;
            sum += sequence[end];
        }
        else if (sum < k)
        {
            end++;
            sum += sequence[end];
        }
        else
        {
            sum -= sequence[start];
            start++;
        }
    }
    
    sort(answer_list.begin(), answer_list.end(), compare);
    
    answer.push_back(answer_list[0].first);
    answer.push_back(answer_list[0].second);
    
    return answer;
}
