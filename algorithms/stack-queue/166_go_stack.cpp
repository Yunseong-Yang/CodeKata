// Date: 2026-08-09
// BOJ 3425

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    string s;
    vector<string> commands;

    while (true)
    {
        cin >> s;
        if (s == "QUIT")
        {
            break;
        }
        if (s == "NUM")
        {
            string s2;
            cin >> s2;
            s += s2;
        }

        if (s == "END")
        {
            int t;
            cin >> t;
            for (int i = 0; i < t; ++i)
            {
                long long a;
                stack<long long> st;
                cin >> a;
                st.push(a);

                bool flag = false;

                for (string command : commands)
                {
                    if (command == "POP")
                    {
                        if (st.empty())
                        {
                            flag = true;
                            break;
                        }
                        st.pop();
                    }
                    else if (command == "INV")
                    {
                        if (st.empty())
                        {
                            flag = true;
                            break;
                        }
                        long long val = st.top();
                        st.pop();
                        st.push(-val);
                    }
                    else if (command == "DUP")
                    {
                        if (st.empty())
                        {
                            flag = true;
                            break;
                        }
                        st.push(st.top());
                    }
                    else if (command == "SWP")
                    {
                        if (st.size() < 2)
                        {
                            flag = true;
                            break;
                        }
                        long long first = st.top();
                        st.pop();
                        long long second = st.top();
                        st.pop();
                        st.push(first);
                        st.push(second);
                    }
                    else if (command == "ADD" || command == "SUB" || command == "MUL" || command == "DIV" || command == "MOD")
                    {
                        if (st.size() < 2)
                        {
                            flag = true;
                            break;
                        }

                        long long first = st.top();
                        st.pop();
                        long long second = st.top();
                        st.pop();
                        long long val = 0;

                        if (command == "ADD")
                        {
                            val = second + first;
                        }
                        else if (command == "SUB")
                        {
                            val = second - first;
                        }
                        else if (command == "MUL")
                        {
                            val = second * first;
                        }
                        else if (command == "DIV")
                        {
                            if (first == 0)
                            {
                                flag = true;
                                break;
                            }
                            val = second / first;
                        }
                        else if (command == "MOD")
                        {
                            if (first == 0)
                            {
                                flag = true;
                                break;
                            }
                            val = second % first;
                        }

                        if (abs(val) > pow(10, 9))
                        {
                            flag = true;
                            break;
                        }
                        st.push(val);
                    }
                    else
                    {
                        long long val = stoll(command.substr(3));
                        st.push(val);
                    }
                }

                if (flag || st.size() != 1)
                {
                    cout << "ERROR" << "\n";
                }
                else
                {
                    cout << st.top() << "\n";
                }
            }
            cout << "\n";
            commands.clear();
        }
        else if (s != "END")
        {
            commands.push_back(s);
        }
    }

    return 0;
}
