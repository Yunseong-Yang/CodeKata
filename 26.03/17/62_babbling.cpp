#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> v;
    v.push_back("aya");
    v.push_back("ma");
    v.push_back("woo");
    v.push_back("ye");
    
    for (int i = 0; i < babbling.size(); i++)
    {
        int last_index = 0;
        int pre_index = -1;
        for (int k = 0; k < 4; k++)
        {
            if (babbling[i].size() >= v[k].size() + last_index 
                && v[k] == babbling[i].substr(last_index, v[k].size()))
            {
                if (pre_index == k)
                {
                    break;
                }
                last_index += v[k].size();
                pre_index = k;
                k = -1;
                continue;
            }
        }
        if (last_index == babbling[i].size())
        {
            answer++;
        }
    }
    
    return answer;
}
