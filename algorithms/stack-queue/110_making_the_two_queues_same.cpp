// Date: 2026-04-30
// https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    long long total = 0;
    long long target = 0;
    
    for (int i = 0; i < queue1.size(); ++i)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    total = sum1 + sum2;
    target = total / 2;
    
    int q1_pointer = 0;
    int q2_pointer = 0;
    int max_limit = queue1.size() * 3;
    
    while(q1_pointer != queue1.size() && q2_pointer != queue2.size())
    {
        if (total % 2 == 1 || answer > max_limit)
        {
            return -1;
        }
        
        if (sum1 == sum2)
        {
            break;
        }
        
        if (sum1 > target)
        {
            queue2.push_back(queue1[q1_pointer]);
            sum1 -= queue1[q1_pointer];
            sum2 += queue1[q1_pointer];
            q1_pointer++;
        }
        else if (sum2 > target)
        {
            queue1.push_back(queue2[q2_pointer]);
            sum1 += queue2[q2_pointer];
            sum2 -= queue2[q2_pointer];
            q2_pointer++;
        }
        answer++;
    }
    
    if (q1_pointer == queue1.size() || q2_pointer == queue2.size())
    {
        return -1;
    }
    else
    {
        return answer++;
    }
}
