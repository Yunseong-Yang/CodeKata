// https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> v;
    string answer = "";
    stringstream ss(s);
    string token;
    
    while(getline(ss, token, ' '))
    {
        v.push_back(stoi(token));
    }
    
    sort(v.begin(), v.end());
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size() - 1]);
    
    return answer;
}
