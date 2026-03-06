// https://school.programmers.co.kr/learn/courses/30/lessons/12948

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string back_number = "";
    for (int i = 3; i >= 0; i--)
    {
        back_number = back_number + phone_number[phone_number.size() - i - 1];
    }
    string front_number = "";
    for (int i = 0; i < phone_number.size() - 4; i++)
    {
        front_number = front_number + "*";
    }
    
    string answer = front_number + back_number;
    
    return answer;
}
