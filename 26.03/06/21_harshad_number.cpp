// https://school.programmers.co.kr/learn/courses/30/lessons/12947

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int original = x;
    int n = 0;
    while (x != 0)
    {
        n += x % 10;
        x /= 10;
    }
    
    return original % n == 0 ? true : false;
}
