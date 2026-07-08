// Date: 2026-07-08
// BOJ 1285

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int min_val = 999999;
vector<vector<char>> arr(21, vector<char>(21));

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char a;
            cin >> a;
            arr[i][j] = a;
        }
    }

    for (int i = 0; i < (1 << n); ++i)
    {
        int total = 0;

        for (int j = 0; j < n; ++j)
        {
            int front = 0;
            int back = 0;

            for (int k = 0; k < n; ++k)
            {
                char current = arr[k][j];

                if ((i & (1 << k)) != 0)
                {
                    current = current == 'H' ? 'T' : 'H';
                }

                if (current == 'H')
                {
                    front++;
                }
                else
                {
                    back++;
                }
            }

            total += front < back ? front : back;
        }

        if (min_val > total)
        {
            min_val = total;
        }
    }

    cout << min_val;

    return 0;
}