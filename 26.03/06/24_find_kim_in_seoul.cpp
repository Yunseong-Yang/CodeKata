// https://school.programmers.co.kr/learn/courses/30/lessons/12919

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string name = "Kim";
    int index = 0;
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == name)
        {
            index = i;
            break;
        }
    }
    
    string answer = "김서방은 " + to_string(index) + "에 있다";
    return answer;
}
