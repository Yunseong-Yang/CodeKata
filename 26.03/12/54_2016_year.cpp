// https://school.programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

void definition(map<int, int>& m)
{
    m.insert({1, 31});
    m.insert({2, 29});
    m.insert({3, 31});
    m.insert({4, 30});
    m.insert({5, 31});
    m.insert({6, 30});
    m.insert({7, 31});
    m.insert({8, 31});
    m.insert({9, 30});
    m.insert({10, 31});
    m.insert({11, 30});
    m.insert({12, 31});
}

string solution(int a, int b) {
    string answer = "";
    map<int, int> m;
    definition(m);
    
    int sum = 0;
    for (int i = 1; i < a; i++)
    {
        sum += m[i];
    }
    
    sum += b;

    switch(sum % 7)
    {
        case 0:
            answer = "THU";
            break;
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
    }
    
    return answer;
}
