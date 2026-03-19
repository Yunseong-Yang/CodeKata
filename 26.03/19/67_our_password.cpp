// https://school.programmers.co.kr/learn/courses/30/lessons/155652

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void check(char& n)
{
    if (n > 'z')
    {
        n = 'a';
    }
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (char c : s)
    {
        char current = c;
        for (int i = 0; i < index; i++)
        {
            current = current + 1;
            check(current);
            
            while(find(skip.begin(), skip.end(), current) != skip.end())
            {
                current++;
                check(current);
            }
        }
        answer += current;
    }
    return answer;
}
