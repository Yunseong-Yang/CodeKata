// Date: 2026-06-11
// https://school.programmers.co.kr/learn/courses/30/lessons/181188

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }
    else
    {
        return a[1] < b[1];   
    }
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    
    int end = -1; 

    for(int i = 0; i < targets.size(); ++i)
    {
        if (targets[i][0] >= end) 
        {
            answer++; 
            end = targets[i][1]; 
        }
    }
    
    return answer;
}