// https://school.programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

void definition(map<string, char>& m)
{
    m.insert({"zero" , '0'});
    m.insert({"one" , '1'});
    m.insert({"two" , '2'});
    m.insert({"three" , '3'});
    m.insert({"four" , '4'});
    m.insert({"five" , '5'});
    m.insert({"six" , '6'});
    m.insert({"seven" , '7'});
    m.insert({"eight" , '8'});
    m.insert({"nine" , '9'});
}

int solution(string s) {
    map<string, char> m;
    definition(m);
    
    string str = "";
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            str += s[i];
            if (m.find(str) != m.end())
            {
                answer += m[str];
                str = "";
            }
        }
        else
        {
            answer += s[i];
        }
    }
    
    return atoi(answer.c_str());
}
