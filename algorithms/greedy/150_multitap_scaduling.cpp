// Date: 2026-07-13
// BOJ 1700

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;

    vector<int> v;
    vector<int> arr;
    for (int i = 0; i < k; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        // 이미 해당 전기 용품이 플러그에 꽃혀있다면
        if (find(arr.begin(), arr.end(), v[i]) != arr.end())
        {
            continue;
        }

        // 멀티탭의 구멍이 존재한다면 일단 n개 만큼 먼저 꽂음
        if (arr.size() != n)
        {
            arr.push_back(v[i]);
            continue;
        }
        else
        {
            // 멀티탭의 구멍이 존재하지 않다면
            // 멀티탭에 꽃힌 각 전기용품이 언제 다시 사용되는지를 점검
            vector<int> temp;
            bool flag = false;
            for (int j = 0; j < arr.size(); ++j)
            {
                auto it = find(v.begin() + i, v.end(), arr[j]);
                if (it == v.end())
                {
                    flag = true;
                    arr[j] = v[i];
                    cnt++;
                    break;
                }
                int t = it - v.begin();
                temp.push_back(t);
            }

            if (flag) continue;

            // 가장 뒤에서 참조되는 얘들 먼저 빼고 현재 사용할 전기 물품을 삽입
            int index = 0;
            for (int j = 1; j < temp.size(); ++j)
            {
                if (temp[index] < temp[j])
                {
                    index = j;
                }
            }

            arr[index] = v[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}