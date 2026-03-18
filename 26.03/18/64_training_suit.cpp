// https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lost_cnt = lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                lost_cnt--;
            }
        }
    }
    
    for (int i = 0; i < reserve.size(); i++)
    {
        if (reserve[i] == -1)
        {
            continue;
        }
        for (int j = 0; j < lost.size(); j++)
        {
            if (lost[j] == -1)
            {
                continue;
            }
            
            if (lost[j] + 1 == reserve[i] || lost[j] - 1 == reserve[i])
            {
                lost[j] = -1;
                reserve[i] = -1;
                lost_cnt--;
                break;
            }
        }
    }
    
    return n - lost_cnt;
}
