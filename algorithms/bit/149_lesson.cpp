#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, max_val;
vector<int> arr;

void dfs(int index, int cnt, int bits)
{
    // 최종 횟수에 다다를 때
    if (cnt == k - 5)
    {
        // 해당 조합에서 단어와 일치한다면
        int temp_val = 0;
        for (int num : arr)
        {
            // 이 단어는 통과한 것이므로 1을 증가
            if ((num & bits) == num)
            {
                temp_val++;
            }
        }

        // 각 조합마다 테스트해보면서 더 많은 단어를 배울 때까지 최댓값 갱신
        if (max_val < temp_val)
        {
            max_val = temp_val;
        }
        return;
    }

    // 이미 없는 비트를 기반으로 하나씩 조합을 수행한다.
    for (int i = index; i < 26; ++i)
    {
        if ((bits & (1 << i)) == 0)
        {
            dfs(i + 1, cnt + 1, bits | (1 << i));
        }
    }
}

int main()
{
    cin >> n >> k;
    arr.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        int a = 0;
        for (char c : s)
        {
            // 이미 체크한 단어는 비트를 올리지 말 것
            if ((a & (1 << (c - 'a'))) == 0)
            {
                a += (1 << (c - 'a'));
            }
        }
        arr[i] = a;
    }

    if (k < 5)
    {
        cout << 0 << "\n";
        return 0;
    }
    else if (k == 26)
    {
        cout << n << "\n";
        return 0;
    }

    int bits = 0;
    bits += (1 << ('a' - 'a'));
    bits += (1 << ('n' - 'a'));
    bits += (1 << ('t' - 'a'));
    bits += (1 << ('i' - 'a'));
    bits += (1 << ('c' - 'a'));

    dfs(0, 0, bits);

    cout << max_val;

    return 0;
}