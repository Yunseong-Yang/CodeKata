// Date: 2026-07-23
// BOJ 13144

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
bool visited[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    long long cnt = 0;
    int right = 0;

    for (int left = 0; left < n; ++left)
    {
        while (right < n && !visited[v[right]])
        {
            visited[v[right]] = true;
            right++;
        }

        cnt += (right - left);

        visited[v[left]] = false;
    }

    cout << cnt << "\n";

    return 0;
}