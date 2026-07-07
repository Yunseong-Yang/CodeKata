// Date: 2026-07-07
// BOJ 14391

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, max_val;

int main()
{
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char a;
            cin >> a;
            v[i][j] = a - '0';
        }
    }
    
    int bit = 1 << (n * m);
    for (int t = 0; t < bit; ++t)
    {
        int total = 0;

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = 0; j < m; ++j)
            {
                int k = i * m + j;

                if ((t & (1 << k)) == 0)
                {
                    sum = sum * 10 + v[i][j];
                }
                else
                {
                    total += sum;
                    sum = 0;
                }
            }
            total += sum;
        }

        for (int j = 0; j < m; ++j)
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                int k = i * m + j;

                if ((t & (1 << k)) != 0)
                {
                    sum = sum * 10 + v[i][j];
                }
                else
                {
                    total += sum;
                    sum = 0;
                }
            }
            total += sum;
        }

        max_val = max(max_val, total);
    }

    cout << max_val;

    return 0;
}