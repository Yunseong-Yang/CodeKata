// Date: 2026-05-14
// https://school.programmers.co.kr/learn/courses/30/lessons/140107

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    int max_num = d / k;
    
    for (int i = 0; i <= max_num; ++i)
    {
        long long x = i * k;
        long long y = sqrt((long long)d * d - x * x);
        answer += (y / k + 1);
    }
    
    return answer;
}