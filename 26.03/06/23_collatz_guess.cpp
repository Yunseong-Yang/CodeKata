// https://school.programmers.co.kr/learn/courses/30/lessons/12943

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = (long)num;
    for (int i = 0; i < 500; i++)
    {
        if (n == 1) return i;
        
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
    }
    
    return -1;
}
