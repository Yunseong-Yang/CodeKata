// Date: 2026-06-04
// https://school.programmers.co.kr/learn/courses/30/lessons/340212

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    
    while (left < right)
    {
        int mid = (left + right) / 2;
        long long result = 0;
        for (int i = 0; i < diffs.size(); ++i)
        {
            if (diffs[i] > mid)
            {
                result += ((long long)times[i - 1] + times[i]) * (diffs[i] - mid) + times[i];
            }
            else
            {
                result += times[i];
            }
        }
        
        if (result > limit)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    
    return left;
}