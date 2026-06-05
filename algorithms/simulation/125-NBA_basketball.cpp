// Date: 2026-06-05
// BOJ 2852

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int convert(string s)
{
    int second = stoi(s.substr(0, 2)) * 60;
    second += stoi(s.substr(3, 2));

    return second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> v;
    int arr[2] = { 0, 0 };
    int time[2] = { 0, 0 };
    int prev_team = 0;
    string prev_time = "";

    for (int i = 0; i < n; ++i)
    {
        int a;
        string b;
        cin >> a >> b;

        if (arr[0] > arr[1])
        {
            time[0] += convert(b) - convert(prev_time);
        }
        else if (arr[0] < arr[1])
        {
            time[1] += convert(b) - convert(prev_time);
        }

        arr[a - 1]++;
        prev_team = a;
        prev_time = b;
    }

    if (arr[0] > arr[1])
    {
        time[0] += 48 * 60 - convert(prev_time);
    }
    else if (arr[0] < arr[1])
    {
        time[1] += 48 * 60 - convert(prev_time);
    }

    string m1 = ((time[0] / 60) >= 0 && (time[0] / 60) <= 9) ? ("0" + to_string(time[0] / 60)) : to_string(time[0] / 60);
    string s1 = ((time[0] % 60) >= 0 && (time[0] % 60) <= 9) ? ("0" + to_string(time[0] % 60)) : to_string(time[0] % 60);

    string m2 = ((time[1] / 60) >= 0 && (time[1] / 60) <= 9) ? ("0" + to_string(time[1] / 60)) : to_string(time[1] / 60);
    string s2 = ((time[1] % 60) >= 0 && (time[1] % 60) <= 9) ? ("0" + to_string(time[1] % 60)) : to_string(time[1] % 60);

    cout << m1 << ":" << s1 << "\n";
    cout << m2 << ":" << s2 << "\n";

    return 0;
}
