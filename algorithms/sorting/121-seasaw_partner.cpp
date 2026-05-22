// Date: 2026-05-22
// https://school.programmers.co.kr/learn/courses/30/lessons/152996

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    
    for (int i = 0; i < weights.size(); ++i)
    {
        int value = weights[i];
        answer += upper_bound(weights.begin() + i + 1, weights.end(), value) - lower_bound(weights.begin() + i + 1, weights.end(), value);
        
        if (value % 3 == 0)
        {
            answer += upper_bound(weights.begin() + i + 1, weights.end(), value * 4 / 3) - lower_bound(weights.begin() + i + 1, weights.end(), value * 4 / 3);
        }
        
        if (value % 2 == 0)
        {
            answer += upper_bound(weights.begin() + i + 1, weights.end(), value * 3 / 2) - lower_bound(weights.begin() + i + 1, weights.end(), value * 3 / 2);
        }
        
        answer += upper_bound(weights.begin() + i + 1, weights.end(), value * 2) - lower_bound(weights.begin() + i + 1, weights.end(), value * 2);
    }

    return answer;
}