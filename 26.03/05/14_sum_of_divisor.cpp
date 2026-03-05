#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        n % i == 0 ? answer += i : 0;
    }
    return answer + n;
}
