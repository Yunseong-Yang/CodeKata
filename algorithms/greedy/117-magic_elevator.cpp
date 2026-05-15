// Date: 2026-05-15
// https://school.programmers.co.kr/learn/courses/30/lessons/148653

#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey != 0)
    {
        int current = storey % 10;
        storey /= 10;
        
        if (current == 5)
        {
            int next = storey % 10;
            if (next >= 5)
            {
                storey += 1;
            }
            answer += current;
        }
        else if (current < 5)
        {
            answer += current;
        }
        else
        {
            storey += 1;
            answer += (10 - current);
        }
    }
    
    return answer;
}