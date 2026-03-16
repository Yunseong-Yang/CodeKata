// https://school.programmers.co.kr/learn/courses/30/lessons/77484

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
void definition(map<int, int>& m)
{
    m[6] = 1;
    m[5] = 2;
    m[4] = 3;
    m[3] = 4;
    m[2] = 5;
    m[1] = 6;
    m[0] = 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int, int> m;
    int lower = 0;
    int greater = 0;
    
    definition(m);
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int win_index = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            greater++;
            continue;
        }
        else
        {
            if (lottos[i] == win_nums[win_index])
            {
                lower++;
                greater++;
                win_index++;
            }
            else if (lottos[i] > win_nums[win_index])
            {
                win_index++;
                i--;
            }
        }
    }
    
    answer.push_back(m[greater]);
    answer.push_back(m[lower]);
    
    return answer;
}
