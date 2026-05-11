// Date: 2026-05-11
// https://school.programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> board(N + 1);
    for (const auto& r : road) 
    {
        board[r[0]].push_back({r[1], r[2]});
        board[r[1]].push_back({r[0], r[2]});
    }
    
    vector<int> dist(N + 1, INF);
    
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < board[current].size(); ++i) 
        {
            int n = board[current][i].first;
            int time = board[current][i].second;
            
            if (dist[current] + time < dist[n]) 
            {
                dist[n] = dist[current] + time;
                q.push(n);
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) 
    {
        if (dist[i] <= K) 
        {
            answer++;
        }
    }
    
    return answer;
}