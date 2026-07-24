#include <iostream>
#include <vector>
#include <string>

using namespace std;

int t, k;
vector<string> v;

string convert(int dir, string s)
{
    if (dir == -1)
    {
        char temp = s[0];

        for (int i = 0; i < s.size() - 1; ++i)
        {
            s[i] = s[i + 1];
        }

        s[s.size() - 1] = temp;
    }
    else
    {
        char temp = s[s.size() - 1];

        for (int i = s.size() - 1; i > 0; --i)
        {
            s[i] = s[i - 1];
        }

        s[0] = temp;
    }

    return s;
}

int main()
{
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        vector<int> dirs(1001);
        int n, d;
        cin >> n >> d;
        n = n - 1;
        dirs[n] = d;

        for (int j = n - 1; j >= 0; --j)
        {
            if (v[j + 1][6] != v[j][2])
            {
                dirs[j] = -dirs[j + 1];
            }
            else
            {
                break;
            }
        }

        for (int j = n; j < t - 1; ++j)
        {
            if (v[j][2] != v[j + 1][6])
            {
                dirs[j + 1] = -dirs[j];
            }
            else
            {
                break;
            }
        }

        for (int j = 0; j < t; ++j)
        {
            if (dirs[j] != 0)
            {
                v[j] = convert(dirs[j], v[j]);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i][0] == '1')
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}