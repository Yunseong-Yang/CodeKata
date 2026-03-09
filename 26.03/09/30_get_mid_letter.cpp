// https://school.programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int mid = s.size() / 2;
    if (s.size() % 2 == 0)
    {
        cout << mid << endl;
        answer = s[mid - 1];
        answer += s[mid];
    }
    else
    {
        answer = s[mid];
    }
    
    return answer;
}
