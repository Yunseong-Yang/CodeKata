// Date: 2026-06-26

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string transition(int n, int m)
{
    string s;
    while(m != 0)
    {
        s += to_string(m % 2);
        m /= 2;
    }
    while(s.size() != n)
    {
        s = s + '0';
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = s[i] == '0' ? ' ' : '#';
    }
    
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; ++i)
    {
        string s;
        int m = arr1[i] | arr2[i];
        
        s = transition(n, m);
        answer.push_back(s);
    }
    
    return answer;
}