// https://school.programmers.co.kr/learn/courses/30/lessons/136798

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getDivisor(int n)
{
    int answer = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            answer++;
        }
    }
    
    return answer;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++)
    {
        int divisor_cnt = getDivisor(i);
        if (divisor_cnt > limit)
        {
            answer += power;
        }
        else
        {
            answer += divisor_cnt;
        }
    }
    
    return answer;
}
