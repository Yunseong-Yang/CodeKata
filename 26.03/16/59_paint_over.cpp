// https://school.programmers.co.kr/learn/courses/30/lessons/161989

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int last_index = 0;
    
    for (int i = 0; i < section.size(); i++)
    {
        if (section[i] > last_index)
        {
            answer++;
            last_index = section[i] + (m - 1);
        }
    }
    
    return answer;
}
