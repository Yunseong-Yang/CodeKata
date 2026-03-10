// https://school.programmers.co.kr/learn/courses/30/lessons/68935

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    string res = "";
    while(n != 0)
    {
        int remainer = 0;
        remainer = n % 3;
        n /= 3;
        res += to_string(remainer);
    }

    int answer = 0;
    int index = 0;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        answer += (pow(3, index) * (res[i] - '0'));
        index++;
    }
    
    return answer;
}
