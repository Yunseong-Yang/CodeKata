// https://school.programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size() == 4 || s.size() == 6)
    {
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s[i] - '0' > 9)
            {
                return false;
            }
        }
        return true;
    }
    
    return false;
}
