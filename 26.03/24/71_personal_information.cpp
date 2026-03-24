// https://school.programmers.co.kr/learn/courses/30/lessons/150370

#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, string> m;
    for (int i = 0; i < terms.size(); i++)
    {
        string s = "";
        for (int j = 2; j < terms[i].size(); j++)
        {
            s += terms[i][j];
        }
        m[terms[i][0]] = s;
    }
    
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));
    
    int today_total = today_year * 12 * 28 + today_month * 28 + today_day;
    
    for (int i = 0; i < privacies.size(); i++)
    {
        string valid_period = privacies[i].substr(0, 10);
        char term = privacies[i][privacies[i].size() - 1];
        
        int term_month = stoi(m[term]);
        
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        
        int privacy_total = year * 12 * 28 + month * 28 + day;
        
        if (privacy_total + term_month * 28 - 1 < today_total)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
