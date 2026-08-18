// Date: 2026-08-18
// BOJ 23284

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int n;
vector<vector<int>> result;

void dfs(vector<int> output, stack<int> st, int k)
{
    if (output.size() == n)
    {
        for (int num : output)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    if (!st.empty())
    {
        vector<int> noutput = output;
        stack<int> nst = st;

        noutput.push_back(nst.top());
        nst.pop();
        dfs(noutput, nst, k);
    }

    if (k <= n)
    {
        st.push(k);
        dfs(output, st, k + 1);
    }
}

int main(void)
{
    cin >> n;
    result.resize(n);

    vector<int> output;
    stack<int> st;
    dfs(output, st, 1);

    return 0;
}
