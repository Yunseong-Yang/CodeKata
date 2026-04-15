// https://school.programmers.co.kr/learn/courses/30/lessons/132265

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_set<int> left;
    unordered_map<int, int> right;
    
    for (int n : topping)
    {
        right[n]++;
    }
    
    for (int n : topping)
    {
        left.insert(n);
        right[n]--;
        if (right[n] == 0)
        {
            right.erase(n);
        }
        
        if (left.size() == right.size())
        {
            answer++;
        }
    }
    
    return answer;
}
