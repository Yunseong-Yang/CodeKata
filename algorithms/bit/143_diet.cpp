#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
vector<int> index_list;
int min_result = 999999;

void check(const vector<vector<int>>& list, const vector<int>& v2)
{
    vector<int> sum(4);
    int result = 0;
    for (int n : v2)
    {
        for (int i = 0; i < 4; ++i)
        {
            sum[i] += list[n - 1][i];
        }

        result += list[n - 1][4];
    }

    if (sum[0] >= v[0] && sum[1] >= v[1] && sum[2] >= v[2] && sum[3] >= v[3])
    {
        if (result < min_result)
        {
            min_result = result;

            index_list.assign(v2.begin(), v2.end());
        }
        else if (result == min_result)
        {
            if (v2 < index_list)
            {
                index_list = v2;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < 4; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<vector<int>> list(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        list[i].push_back(a);
        list[i].push_back(b);
        list[i].push_back(c);
        list[i].push_back(d);
        list[i].push_back(e);
    }

    int k = 1;
    while (k != pow(2, n))
    {
        int a = k;
        int index = 1;
        vector<int> v2;
        while (a != 0)
        {
            if (a & 1)
            {
                v2.push_back(index);
            }
            index++;
            a = a >> 1;
        }

        check(list, v2);
        k++;
    }

    if (min_result == 999999)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << min_result << "\n";
        for (int x : index_list)
        {
            cout << x << " ";
        }
    }

    return 0;
}