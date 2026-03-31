// https://school.programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for (vector<string> cloth : clothes)
    {
        m[cloth[1]]++;
    }
    
    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1);
    }
    
    return answer - 1;
}
