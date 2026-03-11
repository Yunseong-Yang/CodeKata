// https://school.programmers.co.kr/learn/courses/30/lessons/68644

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    for (int i = 0; i < numbers.size(); i++){
        for (int j = i + 1; j < numbers.size(); j++){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer;
    for(const auto& p : s){
        answer.push_back(p);
    }
    
    return answer;
}
