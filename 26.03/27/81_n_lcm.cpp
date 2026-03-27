// https://school.programmers.co.kr/learn/courses/30/lessons/12953

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int max = *max_element(arr.begin(), arr.end());
    long long last = 1;
    for (int n : arr)
    {
        last *= n;
    }
    
    for (int i = 1; i <= last; i++)
    {
        bool is_lcm = true;
        int lcm = max * i;
        for (int j = 0; j < arr.size(); j++)
        {
            if (lcm % arr[j] != 0)
            {
                is_lcm = false;
                break;
            }
        }
        
        if (is_lcm)
        {
            answer = lcm;
            break;
        }
    }
    
    return answer;
}
