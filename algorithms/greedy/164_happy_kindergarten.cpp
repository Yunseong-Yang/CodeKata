// Date: 2026-08-08
// BOJ 13164

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;

int cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> diff;

    for (int i = 0; i < n - 1; ++i)
    {
        diff.push_back(v[i + 1] - v[i]);
    }

    sort(diff.begin(), diff.end(), cmp);

    int result = 0;
    for (int i = k - 1; i < n - 1; ++i)
    {
        result += diff[i];
    }

    cout << result;
    return 0;
}
