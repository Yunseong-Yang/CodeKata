// https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    
    for (int i = 0; i < number.size(); i++) 
    {
        while (!st.empty() && k > 0 && st.top() < number[i]) 
        {
            st.pop();
            k--;
        }
        
        st.push(number[i]);
    }
    
    while (k > 0)
    {
        st.pop();
        k--;
    }
    
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
