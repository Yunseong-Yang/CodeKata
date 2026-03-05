#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-' || s[i] == '+')
        {
            continue;
        }
        answer += (s[i] - '0') * pow(10, s.size() - i - 1);
    }
    return s[0] == '-' ? answer * -1 : answer;
}
