// https://school.programmers.co.kr/learn/courses/30/lessons/12930

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    int i = 0;
    while (index != s.size())
    {
        if (s[index] == ' ')
        {
            i = 0;
            index++;
            answer += ' ';
            continue;
        }
        if (i % 2 == 0)
        {
            if (s[index] >= 'a' && s[index] <= 'z')
            {
                answer += s[index] - 32;
            }
            else
            {
                answer += s[index];
            }
        }
        else
        {
            if (s[index] >= 'A' && s[index] <= 'Z')
            {
                answer += s[index] + 32;
            }
            else
            {
                answer += s[index];
            }
        }
        index++;
        i++;
    }
    return answer;
}
