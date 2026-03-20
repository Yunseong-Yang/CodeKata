// https://school.programmers.co.kr/learn/courses/30/lessons/133502

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    vector<int> correct = {1, 2, 3, 1};
    
    for (int i = 0; i < ingredient.size(); i++)
    {
        bool is_craftable = true;
        stack.push_back(ingredient[i]);
        
        if (stack.size() >= 4)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (stack[stack.size() - j] != correct[4 - j])
                {
                    is_craftable = false;
                    break;
                }
            }
            if (is_craftable)
            {
                for (int j = 0; j < 4; j++)
                {
                    stack.pop_back();
                }
                answer++;
            }
        }
    }
    
    return answer;
}
