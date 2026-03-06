// https://school.programmers.co.kr/learn/courses/30/lessons/12933

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string s1 = to_string(n);
    
    sort(s1.rbegin(), s1.rend());
    
    long long answer = stoll(s1);
    
    return answer;
}
