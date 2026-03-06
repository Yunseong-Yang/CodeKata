// https://school.programmers.co.kr/learn/courses/30/lessons/12935

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int smallest = arr[0];
    int index = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
            index = i;
        }
    }
    
    arr.erase(arr.begin() + index);
    if (arr.empty())
    {
        answer.push_back(-1);
        return answer;
    } 
    else {
        return arr;
    }
}
