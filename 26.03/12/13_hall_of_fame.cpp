// https://school.programmers.co.kr/learn/courses/30/lessons/138477

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < score.size(); i++)
    {
        if (i + 1 <= k)
        {
            pq.push(score[i]);
            answer.push_back(pq.top());
            continue;
        }
        if (pq.top() < score[i])
        {
            pq.pop();
            pq.push(score[i]);
        }
        answer.push_back(pq.top());
    }
    return answer;
}
