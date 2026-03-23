// https://school.programmers.co.kr/learn/courses/30/lessons/161990

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    pair<int, int> low_index = { 51, 51 };
    pair<int, int> high_index = { -1, -1 };
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (low_index.second > j)
                {
                    low_index.second = j;
                }
                if (high_index.second < j)
                {
                    high_index.second = j;
                }
                if (low_index.first > i)
                {
                    low_index.first = i;
                }
                if (high_index.first < i)
                {
                    high_index.first = i;
                }
            }
        }
    }
    
    if (low_index.first < high_index.first)
    {
        answer.push_back(low_index.first);
        if (low_index.second < high_index.second)
        {
            answer.push_back(low_index.second);
            answer.push_back(high_index.first + 1);
            answer.push_back(high_index.second + 1);
        }
        else
        {
            answer.push_back(high_index.second);
            answer.push_back(high_index.first + 1);
            answer.push_back(low_index.second + 1);
        }
    }
    else
    {
        answer.push_back(high_index.first);
        if (low_index.second < high_index.second)
        {
            answer.push_back(low_index.second);
            answer.push_back(low_index.first + 1);
            answer.push_back(high_index.second + 1);
        }
        else
        {
            answer.push_back(high_index.second);
            answer.push_back(low_index.first + 1);
            answer.push_back(low_index.second + 1);
        }
    }
    
    return answer;
}
