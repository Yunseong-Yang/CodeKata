// https://school.programmers.co.kr/learn/courses/30/lessons/12914

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> v;
    v.push_back(1);
    v.push_back(1);
    
    for (int i = 2; i <= n; i++)
    {
        v.push_back((v[i - 1] + v[i - 2]) % 1234567);
    }
    
    return v[v.size() - 1];
}
