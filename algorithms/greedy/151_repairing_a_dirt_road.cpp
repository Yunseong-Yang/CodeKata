// Date: 2026-07-14
// BOJ 1911

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;

int cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}

int main()
{
    cin >> n >> l;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({ a, b });
    }
    // 첫 지점 기준으로 정렬
    sort(v.begin(), v.end(), cmp);

    int remain = 0;
    int last = 0;
    int cnt = 0;
    
    for (pair<int, int> p : v)
    {
        int cur = 0;
        // 처음이면 일단 배치
        if (last == 0)
        {
            if ((p.second - p.first) % l == 0)
            {
                cur = (p.second - p.first) / l;
            }
            else
            {
                cur = (p.second - p.first) / l + 1;
            }
        }
        // 아니라면
        else
        {
            // 이전 마지막 지점과 남은 판자가 현재 첫 지점을 넘는다면
            if (last + remain >= p.first)
            {
                // 위치 보정
                p.first = last + remain;
            }

            // 남은 판자가 해당 웅덩이를 완전 덮어버리면 다른 내용 탐색
            if (p.first >= p.second) continue;
            
            if ((p.second - p.first) % l == 0)
            {
                cur = (p.second - p.first) / l;
            }
            else
            {
                cur = (p.second - p.first) / l + 1;
            }
        }

        remain = cur * l - (p.second - p.first);
        last = p.second;
        cnt += cur;
    }

    cout << cnt;

    return 0;
}