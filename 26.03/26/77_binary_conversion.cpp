// https://school.programmers.co.kr/learn/courses/30/lessons/70129
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int conversion_cnt = 0;
    int zero_cnt = 0;
    
    while(s != "1")
    {
        conversion_cnt++;
        vector<char> v;
        for (char c : s)
        {
            if (c != '0')
            {
                v.push_back(c);
            }
            else
            {
                zero_cnt++;
            }
        }
        
        int length = v.size();
        string temp_str = "";
        while(length != 0)
        {
            temp_str += to_string(length % 2);
            length /= 2;
        }
        string new_str = "";
        for (int i = temp_str.size() - 1; i >= 0; i--)
        {
            new_str += temp_str[i];
        }
        s = new_str;
    }
    
    answer.push_back(conversion_cnt);
    answer.push_back(zero_cnt);
    
    return answer;
}
