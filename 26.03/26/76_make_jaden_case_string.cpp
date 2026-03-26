// https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool is_first = true;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            is_first = true;
            continue;
        }
        else
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                is_first = false;
            }
            else if (is_first && s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 32;
                is_first = false;
            }
            else if (!is_first && s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
            else if (is_first && s[i] >= 'A' && s[i] <= 'Z') 
            {
                is_first = false; 
            }
        }
    }
    
    return s;
}
