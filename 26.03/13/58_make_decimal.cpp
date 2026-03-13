// https://school.programmers.co.kr/learn/courses/30/lessons/12977

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int flag = 0;
                int sum = nums[i] + nums[j] + nums[k];
                for (int l = 2; l <= sum / 2; l++)
                {
                    if (sum % l == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}
