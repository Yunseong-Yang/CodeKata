#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int main() {
    unordered_map<char, char> map;
    map[')'] = '(';
    map[']'] = '[';

    string s;
    while (true)
    {
        getline(cin, s);
        if (s == ".") break;

        stack<char> st;
        bool flag = true;
        for (char c : s)
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')' || c == ']')
            {
                if (st.empty() || (st.top() != map[c]))
                {
                    flag = false;
                    break;
                }

                st.pop();
            }
        }

        if (st.empty() && flag)
        {
            cout << "yes" << "\n";
        }
        else
        {
            cout << "no" << "\n";
        }
    }

    return 0;
}