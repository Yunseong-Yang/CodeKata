// Date: 2026-06-29
// BOJ 1182


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int answer = 0;

    // 비트의 의미 -> 어느 원소를 선택할 것인가? (0, 0, 1, 1) ==> 0, 1 번째 원소 선택
    // 조합을 다르게 처리함.
    for (int mask = 0; mask < (1 << n); ++mask) // 모든 케이스를 다 시도해보고
    {
        int sum = 0;
        // 각 케이스에서 원소 선택.
        for (int i = 0; i < n; ++i)
        {
            if ((mask >> i) & 1) 
            {
                sum += v[i];
            }
        }

        if (s == sum && mask != 0)
        {
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}