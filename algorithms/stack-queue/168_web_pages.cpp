// Date: 2026-08-08
// BOJ 5076

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    while (true)
    {
        string s;
        getline(cin, s);
        if (s == "#") break;


        // <A>를 stack에 넣고 카운팅
        // </A>와 매핑되는 A가 stack의 Top에 있는지 ---> 없으면 x, 있으면 통과
        // <A/>는 스택에 넣지 않음 그냥 통과
        // 최종적으로 스택에 아무것도 없어야 함

        string str;
        int flag = 0;
        stack<string> st;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '<')
            {
                flag = 1;
                continue;
            }

            if (s[i] == '>')
            {
                if (str[0] == '/')
                {
                    if (st.empty() || st.top() != str.substr(1, str.size() - 1))
                    {
                        break;
                    }

                    if (st.top() == str.substr(1, str.size() - 1))
                    {
                        st.pop();
                        str.clear();
                        flag = 0;
                    }
                }
                else
                {
                    if (s[i - 1] != '/')
                    {
                        st.push(str);
                    }
                    flag = 0;
                    str.clear();
                }
                continue;
            }

            if (flag)
            {
                if (s[i] == ' ' && s[i + 1] != '/')
                {
                    flag = 0;
                    continue;
                }

                str += s[i];
            }
        }


        if (st.empty() && !flag)
        {
            cout << "legal" << "\n";
        }
        else
        {
            cout << "illegal" << "\n";
        }
    }


    return 0;
}
