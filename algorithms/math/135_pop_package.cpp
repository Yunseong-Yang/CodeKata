// Date: 2026-06-18
// https://school.programmers.co.kr/learn/courses/30/lessons/389478

#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int floor = (n - 1) / w;
    int diff = (n - 1) % w;
    int cur_floor = (num - 1) / w;
    int cur_diff = (num - 1) % w;
    
    if (cur_floor % 2 == 1)
    {
        cur_diff = (w - 1) - cur_diff; 
    }
    
    if (floor % 2 == 1)
    {
        diff = (w - 1) - diff;
        if (diff <= cur_diff)
        {
            return (floor - cur_floor) + 1;
        }
        else
        {
            return floor - cur_floor;
        }
    }
    else
    {
        if (diff >= cur_diff)
        {
            return (floor - cur_floor) + 1;
        }
        else
        {
            return floor - cur_floor;
        }
    }
    
    return answer;
}