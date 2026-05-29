// Date: 2026-05-29
// https://school.programmers.co.kr/learn/courses/30/lessons/389479

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    
    for (int i = 0; i < players.size(); ++i)
    {
        while(q.front() == i)
        {
            q.pop();
        }
        
        if (players[i] < m) continue;
        else
        {
            if (q.size() < players[i] / m)
            {
                int n = players[i] / m - q.size();
                
                for (int j = 0; j < n; ++j)
                {
                    q.push(i + k);
                    answer++;
                }
            }
        }
    }
    
    return answer;
}