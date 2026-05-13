// Date: 2026-05-13
// https://school.programmers.co.kr/learn/courses/30/lessons/155651

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int timeToMinute(string time) 
{
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<int> room(1450, 0);
    int answer = 0;
    
    for (const auto& time : book_time)
    {
        int startTime = timeToMinute(time[0]);
        int endTime = timeToMinute(time[1]) + 10;
        
        room[startTime] += 1;
        room[endTime] -= 1;
    }
    
    int current = 0;
    
    for (int i : room)
    {
        current += i;
        answer = max(answer, current);
    }
    
    return answer;
}