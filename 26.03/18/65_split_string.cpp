// https://school.programmers.co.kr/learn/courses/30/lessons/140108

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char first;
    int first_cnt = 0;
    int other_cnt = 0;
    
    for (char c : s)
    {
        if (first_cnt == 0)
        {
            first = c;
            first_cnt++;
            continue;
        }
        if (first == c)
        {
            first_cnt++;
        }
        else
        {
            if (first_cnt != other_cnt)
            {
                other_cnt++;
                if (first_cnt == other_cnt)
                {
                    first_cnt = 0;
                    other_cnt = 0;
                    answer++;
                }
            }
        }
    }
    
    if (first_cnt != 0)
    {
        answer++;
    }
    
    return answer;
}
