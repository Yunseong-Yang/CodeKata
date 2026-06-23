// Date: 2026-06-23
// BOJ 2828

#include <iostream>
#include <vector>

using namespace std;

int n, m, j;

int main()
{
    cin >> n >> m >> j;
    vector<int> v;
    for (int i = 0; i < j; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int left = 1;
    int right = m;
    int cnt = 0;
    for (int a : v)
    {
        if (right < a)
        {
            int b = a - right;
            left += b;
            right += b;
            cnt += b;
        }
        else if (left > a)
        {
            int b = left - a;
            left -= b;
            right -= b;
            cnt += b;
        }
    }

    cout << cnt;

    return 0;
}