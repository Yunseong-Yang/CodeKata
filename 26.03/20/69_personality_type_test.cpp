// https://school.programmers.co.kr/learn/courses/30/lessons/118666

#include <string>
#include <vector>
#include <map>

using namespace std;

void definition(map<char, int>& m)
{
    m['R'] = 0;
    m['T'] = 0;
    m['C'] = 0;
    m['F'] = 0;
    m['M'] = 0;
    m['J'] = 0;
    m['A'] = 0;
    m['N'] = 0;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> m;
    definition(m);
    vector<char> keys = {'R', 'T', 'C', 'F', 'M', 'J', 'A', 'N'};
    
    for (int i = 0; i < survey.size(); i++)
    {
        char neg = survey[i][0];
        char pos = survey[i][1];
        
        int line = choices[i] / 4;
        line == 0 ? m[neg] += (4 - choices[i] % 4) : m[pos] += choices[i] % 4;
    }
    
    for (int i = 0; i < 8; i += 2)
    {
        if (m[keys[i]] == m[keys[i + 1]])
        {
            keys[i] < keys[i + 1] ? answer += keys[i] : answer += keys[i + 1];
        }
        else
        {
            m[keys[i]] > m[keys[i + 1]] ? answer += keys[i] : answer += keys[i + 1];
        }
    }
    
    return answer;
}
