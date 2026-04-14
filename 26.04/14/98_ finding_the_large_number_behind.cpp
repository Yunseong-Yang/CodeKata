// https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> st;
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        if (st.empty())
        {
            st.push(numbers[i]);
            continue;
        }
        else
        {
            while (!st.empty() && numbers[i] >= st.top())
            {
                st.pop();
            }
            if (!st.empty())
            {
                answer[i] = st.top();
            }
            st.push(numbers[i]);
        }
    }
    return answer;
}
