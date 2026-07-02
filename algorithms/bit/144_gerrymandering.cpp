// Date: 2026-07-02
// BOJ 17471

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v;
int n;
int arr[11][11];
int min_val = 999999;

bool bfs(int start, int end, const vector<int>& onebit)
{
    queue<int> q;
    q.push(start);
    int visited[11] = { 0, };
    visited[start] = 1;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        if (val == end)
        {
            return true;
        }

        for (int i = 0; i < n; ++i)
        {
            if (val != i)
            {
                if (arr[val][i] == 1 && !visited[i]
                    && find(onebit.begin(), onebit.end(), i) != onebit.end())
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    return false;
}

bool check(const vector<int>& onebit)
{
    if (onebit.size() == n || onebit.empty()) return false;

    for (int i = 0; i < onebit.size(); ++i)
    {
        for (int j = 0; j < onebit.size(); ++j)
        {
            if (i == j) continue;
            if (!bfs(onebit[i], onebit[j], onebit)) return false;
        }
    }

    return true;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j)
        {
            int b;
            cin >> b;
            arr[i][b - 1] = 1;
            arr[b - 1][i] = 1;
        }
    }

    int t = 0;
    while (t != 1 << n)
    {
        vector<int> one_bit;
        int temp = t;

        int index = 0;
        while (temp != 0)
        {

            if (temp & 1)
            {
                one_bit.push_back(index);
            }
            index++;
            temp = temp >> 1;
        }

        vector<int> remain_bit;
        for (int i = 0; i < n; ++i)
        {
            if (find(one_bit.begin(), one_bit.end(), i) != one_bit.end()) continue;
            else
            {
                remain_bit.push_back(i);
            }
        }

        if (check(one_bit) && check(remain_bit))
        {
            int sum1 = 0;
            int sum2 = 0;
            for (int k : one_bit)
            {
                sum1 += v[k];
            }
            for (int k : remain_bit)
            {
                sum2 += v[k];
            }

            if (abs(sum1 - sum2) < min_val)
            {
                min_val = abs(sum1 - sum2);
            }
        }

        t++;
    }

    if (min_val == 999999)
    {
        cout << -1;
    }
    else
    {
        cout << min_val;
    }

    return 0;
}