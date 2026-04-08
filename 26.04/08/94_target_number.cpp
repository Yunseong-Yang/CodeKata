// https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int answer = 0;
void DFS(const vector<int>& numbers, int target, int depth, int sum)
{
    if (depth == numbers.size())
    {
        if (sum == target)
        {
            answer++;
            return;
        }
    }
    else
    {
        DFS(numbers, target, depth + 1, sum + numbers[depth]);
        DFS(numbers, target, depth + 1, sum - numbers[depth]);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 1, numbers[0]);
    DFS(numbers, target, 1, -numbers[0]);
    
    return answer;
}
