// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> str;
    string answer = "";
    
    for (int n : numbers)
    {
        str.push_back(to_string(n));
    }
    
    sort(str.begin(), str.end(), cmp);
    
    if (str[0] == "0")
    {
        return "0";
    }
    
    for (const string& s : str)
    {
        answer += s;
    }
    
    return answer;
}
