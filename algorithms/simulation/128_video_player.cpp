// Date: 2026-06-08
// https://school.programmers.co.kr/learn/courses/30/lessons/340213

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int timeToSec(string str) 
{
    int m = stoi(str.substr(0, 2));
    int s = stoi(str.substr(3, 2));
    return m * 60 + s;
}

string secToTime(int sec) 
{
    string m = (sec / 60 < 10) ? "0" + to_string(sec / 60) : to_string(sec / 60);
    string s = (sec % 60 < 10) ? "0" + to_string(sec % 60) : to_string(sec % 60);
    return m + ":" + s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int vid_len = timeToSec(video_len);
    int cur = timeToSec(pos);
    int start = timeToSec(op_start);
    int end = timeToSec(op_end);
    
    auto skip = [&](int current_time) 
    {
        if (start <= current_time && current_time <= end) 
        {
            return end;
        }
        return current_time;
    };
    
    cur = skip(cur);
    
    for (const string& cmd : commands) 
    {
        if (cmd == "prev") 
        {
            cur = max(0, cur - 10);
        } 
        else if (cmd == "next") 
        {
            cur = min(vid_len, cur + 10);
        }

        cur = skip(cur);
    }
    
    return secToTime(cur);
}