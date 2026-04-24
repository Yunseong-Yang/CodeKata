// https://school.programmers.co.kr/learn/courses/30/lessons/131704

#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub_container;
    queue<int> main_container;
    
    for (int i = 0; i < order.size(); ++i)
    {
        main_container.push(i + 1);
    }
    
    for (int i = 0; i < order.size(); ++i)
    {
        int cur_order = order[i];
        if (!sub_container.empty() && sub_container.top() == cur_order)
        {
            answer++;
            sub_container.pop();
            continue;
        }
        
        while(!main_container.empty() && cur_order != main_container.front())
        {
            sub_container.push(main_container.front());
            main_container.pop();
        }
        
        if (!main_container.empty() && main_container.front() == cur_order)
        {
            answer++;
            main_container.pop();
            continue;
        }
        
        break;
    }
    
    return answer;
}
