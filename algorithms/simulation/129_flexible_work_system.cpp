// Date: 2026-06-09
// https://school.programmers.co.kr/learn/courses/30/lessons/388351

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < schedules.size(); ++i)
    {
        int m = schedules[i] / 100;
        int s = schedules[i] % 100;
        s += 10;
        
        if (s >= 60)
        {
            s %= 60;
            m += 1;
        }
        
        int time = m * 100 + s;
        bool flag = true;
        
        for (int j = 0; j < timelogs[i].size(); ++j)
        {
            if ((startday + j) % 7 != 6 && (startday + j) % 7 != 0 && time < timelogs[i][j])
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            answer++;
        }
    }
    return answer;
}