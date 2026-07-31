// Date: 2026-07-31
// BOJ 2294

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int main() 
{
    cin >> n >> k;
    vector<int> coin;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        coin.push_back(a);
    }

    vector<int> dp(k + 1, 10001);
    dp[0] = 0;

    for (int num : coin)
    {
        for (int i = num; i <= k; ++i)
        {
            dp[i] = min(dp[i - num] + 1, dp[i]);
        }
    }

    if (dp[k] == 10001)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dp[k] << "\n";
    }
    return 0;
}