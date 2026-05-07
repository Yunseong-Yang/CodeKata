// Date: 2026-03-05
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n != 0)
    {
        answer += (n % 10);
        n /= 10;
    }

    return answer;
}
