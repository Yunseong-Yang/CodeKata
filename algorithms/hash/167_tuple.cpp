// Date: 2026-08-16
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int cmp(const vector<int>& a, const vector<int>& b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> list;
    
    int flag = 0;
    vector<int> source;
    string str;
    
    for (char c : s)
    {   
        if (c == '{')
        {
            flag = 1;
            continue;
        }
        if (c == '}')
        {
            if (!str.empty()) 
            {
                source.push_back(stoi(str));
                str = "";
            }
            if (!source.empty()) 
            {
                list.push_back(source);
                source.clear();
            }
            flag = 0;
            continue;
        }
        if (c == ',')
        {
            if (flag == 1 && !str.empty()) 
            {
                source.push_back(stoi(str));
                str = "";
            }
            continue;
        }
        
        if (flag == 1 && c - '0' >= 0 && c - '0' <= 9)
        {
            str += c;
        }
    }
    
    sort(list.begin(), list.end(), cmp);
    
    vector<int> ans;
    unordered_set<int> uset;
    for (int i = 0; i < list.size(); ++i)
    {
        if (ans.empty())
        {
            uset.insert(list[0][0]);
            ans.push_back(list[0][0]);
        }
        else
        {
            for (int n : list[i])
            {
                if (uset.find(n) == uset.end())
                {
                    uset.insert(n);
                    ans.push_back(n);
                }
            }
        }
    }
    
    return ans;
}
