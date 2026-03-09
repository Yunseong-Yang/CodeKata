// https://school.programmers.co.kr/learn/courses/30/lessons/12917

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
    return a > b ? true : false;
}

string solution(string s) {
    sort(s.begin(), s.end(), compare);
    return s;
}
