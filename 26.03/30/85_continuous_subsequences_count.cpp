// https://school.programmers.co.kr/learn/courses/30/lessons/131701

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    
    for (int i = 0; i < elements.size(); i++)
    {
        int val = 0;
        for (int j = 0; j < elements.size(); j++)
        {
            val += elements[(i + j) % elements.size()];
            s.insert(val);
        }
    }
    
    return s.size();
}
