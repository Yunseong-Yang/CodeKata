// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({i, priorities[i]});
    }
    
    int cnt = 1;
    sort(priorities.begin(), priorities.end());
    
    while(!q.empty())
    {
        pair<int, int> val = q.front();
        
        if (val.second < *max_element(priorities.begin(), priorities.end()))
        {
            q.push(val);
        }
        else
        {
            if (val.first == location)
            {
                return cnt;
            }
            else
            {
                cnt++;
                priorities.pop_back();
            }
        }
        q.pop();
    }
    
    return cnt;
}
