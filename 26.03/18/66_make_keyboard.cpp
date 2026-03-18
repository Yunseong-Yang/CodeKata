// https://school.programmers.co.kr/learn/courses/30/lessons/160586

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (string target : targets)
    {
        int result = 0;
        bool is_possible = true;
        for (char c : target)
        {
            int low_index = 101;
            for (string s : keymap)
            {
                auto it = find(s.begin(), s.end(), c);
                if (it != s.end() && low_index > it - s.begin())
                {
                    low_index = it - s.begin();
                }
            }
            
            if (low_index != 101)
            {
                result += (low_index + 1);
            }
            else
            {
                is_possible = false;
                break;
            }
        }
        
        is_possible ? answer.push_back(result) : answer.push_back(-1);
    }
    
    return answer;
}
