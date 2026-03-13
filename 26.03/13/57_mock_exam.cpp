// https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> person1 = {1, 2, 3, 4, 5};
    vector<int> person2 = {2, 1, 2, 3, 2 ,4 ,2, 5};
    vector<int> person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> correct(3, 0);
    
    for (int i = 0; i < answers.size(); i++){
        int p1 = i % person1.size();
        int p2 = i % person2.size();
        int p3 = i % person3.size();
        if (answers[i] == person1[p1]){
            correct[0]++;
        }
        if (answers[i] == person2[p2]){
            correct[1]++;
        }
        if (answers[i] == person3[p3]){
            correct[2]++;
        }
    }
    
    auto m = max_element(correct.begin(), correct.end());
    vector<int> answer;
    
    if (correct[0] == *m){
        answer.push_back(1);
    }
    if (correct[1] == *m){
        answer.push_back(2);
    }
    if (correct[2] == *m){
        answer.push_back(3);
    }
    
    
    return answer;
}
