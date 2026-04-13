// https://school.programmers.co.kr/learn/courses/30/lessons/84512

#include <string>
#include <vector>

using namespace std;

vector<char> v = {'A', 'E', 'I', 'O', 'U'};
int cnt = 0;
int flag = 0;

void DFS(string s, const string& target, int depth)
{
    if (flag == 1 || depth > 5)
    {
        return;
    }
    cnt++;
    
    if (s == target)
    {
        flag = 1;
        return;
    }

    DFS(s + v[0], target, depth + 1);
    DFS(s + v[1], target, depth + 1);
    DFS(s + v[2], target, depth + 1);
    DFS(s + v[3], target, depth + 1);
    DFS(s + v[4], target, depth + 1);
}

int solution(string word) {
    int answer = 0;
    string s = "";
    
    DFS(s + v[0], word, 1);
    DFS(s + v[1], word, 1);
    DFS(s + v[2], word, 1);
    DFS(s + v[3], word, 1);
    DFS(s + v[4], word, 1);
    
    return cnt;
}
