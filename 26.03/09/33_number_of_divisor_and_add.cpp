// https://school.programmers.co.kr/learn/courses/30/lessons/77884

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                cnt++;
            }
        }
        answer = cnt % 2 == 0 ? -1 * i + answer : i + answer;
    }

    return answer;
}
