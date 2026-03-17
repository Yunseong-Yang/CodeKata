// https://school.programmers.co.kr/learn/courses/30/lessons/131128

#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int arr[2][11] = {0};
    
    for (const char& c : X)
    {
        arr[0][c - '0']++;
    }
    for (const char& c : Y)
    {
        arr[1][c - '0']++;
    }
    
    for (int i = 10; i >= 0; i--)
    {
        while (arr[0][i] != 0 && arr[1][i] != 0)
        {
            arr[0][i]--;
            arr[1][i]--;
            answer += (i + '0');
        }
    }
    
    if (answer.empty())
    {
        return "-1";
    }
    
    if (answer[0] == '0')
    {
        return "0";
    }
    
    return answer;
}
