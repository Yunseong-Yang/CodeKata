// https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int chance = discount.size() - 9;
    unordered_map<string, int> hash_map;
    
    for (int i = 0; i < 10; i++)
    {
        hash_map[discount[i]]++;
    }
    
    for (int i = 0; i < chance; i++)
    {
        int flag = 0;
        if (i != 0)
        {
            hash_map[discount[i - 1]]--;
            hash_map[discount[9 + i]]++;
        }
        for (int j = 0; j < want.size(); j++)
        {
            if (hash_map.find(want[j]) != hash_map.end())
            {
                if (hash_map[want[j]] == number[j])
                {
                    continue;
                }
            }
            flag = 1;
            break;
        }
        if (flag) 
        {
            continue;
        } 
        else 
        {
            answer++;
        }
    }
    
    return answer;
}
