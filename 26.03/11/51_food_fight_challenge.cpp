// https://school.programmers.co.kr/learn/courses/30/lessons/134240

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i = 1; i < food.size(); i++)
    {
        food[i] /= 2;
        for (int j = 0; j < food[i]; j++)
        {
            answer += to_string(i);
        }
    }

    answer += '0';
    
    for (int i = food.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < food[i]; j++)
        {
            answer += to_string(i);
        }
    }
    
    
    return answer;
}
