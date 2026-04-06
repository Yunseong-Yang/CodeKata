// https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> result;
    
    sort(dungeons.begin(), dungeons.end());
    
    do
    {
        int fatigue = k;
        int score = 0;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (fatigue < dungeons[i][0])
            {
                break;
            }
            else
            {
                fatigue -= dungeons[i][1];
                score++;
            }
        }
        result.push_back(score);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return *max_element(result.begin(), result.end());
}
