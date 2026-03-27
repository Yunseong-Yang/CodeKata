// https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    
    for (int i = 1; i < n; i++)
    {
        v.push_back((v[i] + v[i - 1]) % 1234567);
    }
    
    return v[v.size() - 1];
}
