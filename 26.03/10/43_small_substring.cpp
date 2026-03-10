// https://school.programmers.co.kr/learn/courses/30/lessons/147355

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i < t.size() - p.size() + 1; i++)
    {
        string s = "";
        for (int j = i; j < i + p.size(); j++)
        {
            s += t[j];
        }
        atoll(s.c_str()) <= atoll(p.c_str()) ? answer++ : 0;
    }
    return answer;
}
