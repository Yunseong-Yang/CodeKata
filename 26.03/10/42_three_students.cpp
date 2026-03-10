// https://school.programmers.co.kr/learn/courses/30/lessons/131705

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for (int i = 0; i < number.size(); i++)
    {
        for (int j = i; j < number.size(); j++)
        {
            for (int k = j; k < number.size(); k++)
            {
                if (i != j && j != k && i != k)
                {
                    cout << i << " " << j << " " << k << endl;
                    number[i] + number[j] + number[k] == 0 ? answer++ : 0;
                }
            }
        }
    }
    return answer;
}
