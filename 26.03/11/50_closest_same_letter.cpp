// https://school.programmers.co.kr/learn/courses/30/lessons/142086

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++)
    {
        int index = i;
        while(index >= 0)
        {
            index--;
            if (s[index] == s[i])
            {
                answer.push_back(i - index);
                break;
            }
            
        }
        if (index < 0)
        {
            answer.push_back(-1);
        }
    }
    return answer;
}
