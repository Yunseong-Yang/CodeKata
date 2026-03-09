// https://school.programmers.co.kr/learn/courses/30/lessons/12940

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int smallest = 0;
    int biggest = 0;
    if (n > m)
    {
        smallest = m;
        biggest = n;
    }
    else
    {
        smallest = n;
        biggest = m;
    }
    
    int gcd = 0;
    int lcm = 0;
    for (int i = 1; i <= smallest; i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            gcd = i;
        }
    }
    for (int i = biggest; i <= n * m; i++)
    {
        if (i % n == 0 && i % m == 0)
        {
            lcm = i;
            break;
        }
    }
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}
