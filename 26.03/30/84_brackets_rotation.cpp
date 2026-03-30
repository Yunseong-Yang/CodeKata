// https://school.programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;
    int flag;
    
    for (int i = 0; i < s.size(); i++){
        flag = 0;
        for (int j = 0; j < s.size(); j++){
            if (st.empty() && (s[j] == ']' || s[j] == '}' || s[j] == ')')){
                flag = 1;
                break;
            }
            
            if (s[j] == '[' || s[j] == '{' || s[j] == '('){
                st.push(s[j]);
            }
            else if ((s[j] == ']' && st.top() == '[') ||
                (s[j] == '}' && st.top() == '{') ||
                (s[j] == ')' && st.top() == '(')){
                st.pop();
            }
        }
        if (st.empty() && !flag)
            answer++;
        
        char a = s[0];
        s = s.substr(1, s.size()) + a;
    }
    return answer;
}
