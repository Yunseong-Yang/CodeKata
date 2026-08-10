#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> arr;

void dfs(int cnt, int start)
{
    if (cnt == m)
    {
        for (int a : arr)
        {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < n; ++i)
    {
        arr.push_back(v[i]);
        dfs(cnt + 1, i);
        arr.pop_back();
    }
}

int main(void)
{
    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    dfs(0, 0);

    return 0;
}
