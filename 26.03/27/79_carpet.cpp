// https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int row = 1;
    int col = yellow;
    
    while (col >= row)
    {
        long long req = 2 * (col + row) + 4;
        
        if (req <= 5000 && req == brown)
        {
            break;
        }
        
        do
        {
            row++;
        } while (yellow % row != 0);
        col = yellow / row;
    }
    
    answer.push_back(col + 2);
    answer.push_back(row + 2);
    
    return answer;
}
