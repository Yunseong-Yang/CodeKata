// https://school.programmers.co.kr/learn/courses/30/lessons/138476

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    
    for (int n : tangerine)
    {
        m[n] != 0 ? m[n]++ : m[n] = 1;
    }
    
    vector<pair<int, int>> v (m.begin(), m.end());
    sort(v.begin(), v.end(), compare);
    
    int cnt = 0;
    for (pair<int, int> pp : v)
    {
        answer++;
        cnt += pp.second;
        if (cnt >= k)
        {
             break;
        }
    }
    
    return answer;
}
