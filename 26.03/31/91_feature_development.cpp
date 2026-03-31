// https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); i++){
        q.push(progresses[i]);
    }
    
    int day = 1;
    int index = 0;
    int count = 0;
    while (!q.empty()){
        if (q.front() + (day * speeds[index]) >= 100){
            count++;
            q.pop();
            index++;
            continue;
        } else {
            if (count != 0) {
                answer.push_back(count);
            }
            day++;
            count = 0;
        }
    }
    answer.push_back(count);
    
    return answer;
}
