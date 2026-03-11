// https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int cnt = sizes.size();
    vector<int> width(cnt);
    vector<int> height(cnt);
    for(int i = 0; i < cnt; i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = temp;
        }
        width[i] = sizes[i][0];
        height[i] = sizes[i][1];
    }
    
    int answer = *max_element(width.begin(), width.end()) * *max_element(height.begin(), height.end());
    return answer;
}
