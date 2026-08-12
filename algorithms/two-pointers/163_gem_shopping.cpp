// Date: 2026-08-12
// https://school.programmers.co.kr/learn/courses/30/lessons/67258

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer;
    unordered_set<string> uset;
    
    for (int i = 0; i < gems.size(); ++i)
    {
        uset.insert(gems[i]);
    }

    unordered_map<string, int> cur_map;
    int left = 0;
    int right = 0;
    
    int min_len = 100001; 
    int min_left = 0;
    int min_right = 0;

    while (true)
    {
        if (cur_map.size() == uset.size())
        {
            if (right - left < min_len)
            {
                min_len = right - left;
                min_left = left;
                min_right = right - 1;
            }
            
            cur_map[gems[left]] -= 1;            
            if (cur_map[gems[left]] == 0)
            {
                cur_map.erase(gems[left]);
            }
            left++;
        }
        else if (right < gems.size())
        {       
            cur_map[gems[right]] += 1;           
            right++;        
        }
        else
        {
            break;
        }
    }
    
    answer.push_back(min_left + 1);
    answer.push_back(min_right + 1);   
    
    return answer;
}
