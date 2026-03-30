// https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int max_val = *max_element(citations.begin(), citations.end());
    
    for ( ; ; max_val--)
    {
        int low_cnt = 0;
        int high_cnt = 0;
        for (int n : citations)
        {
            n >= max_val ? high_cnt++ : low_cnt++;
        }
        
        if (max_val <= high_cnt && max_val >= low_cnt)
        {
            return max_val;
        }
    }
}
