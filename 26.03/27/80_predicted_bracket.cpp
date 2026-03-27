// https://school.programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    if (a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    while(true){
        answer++;
        if ((a % 2 == 1) && (b % 2 == 0) && (b - a == 1)){
            break;
        }
        a = ceil(a / 2.0);
        b = ceil(b / 2.0);
        
        cout << a << b;
    }

    return answer;
}
