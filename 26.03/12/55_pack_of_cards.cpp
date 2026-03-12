// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> list1;
    queue<string> list2;
    
    for (int i = 0; i < cards1.size(); i++){
        list1.push(cards1[i]);
    }
    for (int i = 0; i < cards2.size(); i++){
        list2.push(cards2[i]);
    }
    
    int index = 0;
    
    for (; index < goal.size(); index++){
        if (list1.front() == goal[index] && !list1.empty()){
            list1.pop();
        } else if (list2.front() == goal[index] && !list2.empty()){
            list2.pop();
        } else {
            break;
        }
    }
    
    if (index == goal.size()){
        answer = "Yes";
    } else {
        answer = "No";
    }
    
    return answer;
}
