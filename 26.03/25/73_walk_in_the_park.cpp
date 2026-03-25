// https://school.programmers.co.kr/learn/courses/30/lessons/172928

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    map<char, int> m;
    
    m['E'] = 1;
    m['W'] = -1;
    m['S'] = 1;
    m['N'] = -1;
    
    int col = park[0].size();
    int row = park.size();
    pair<int, int> current;
    
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                current = { i, j };
            }
        }
    }

    for (int i = 0; i < routes.size(); i++)
    {
        pair<int, int> temp = current;
        char dir = routes[i][0];
        int move_cnt = routes[i][2] - '0';
        
        for (int i = 0; i < move_cnt; i++)
        {
            if (dir == 'E' || dir == 'W')
            {
                if (current.second + m[dir] >= 0 && current.second + m[dir] < col
                        && park[current.first][current.second + m[dir]] != 'X')
                {
                    current.second += m[dir];
                }
                else
                {
                    current = temp;
                    break;
                }
            }
            else
            {
                if (current.first + m[dir] >= 0 && current.first + m[dir] < row
                        && park[current.first + m[dir]][current.second] != 'X')
                {
                    current.first += m[dir];
                }
                else
                {
                    current = temp;
                    break;
                }
            }
        }
        cout << current.first << " " << current.second << endl;
    }
    
    answer.push_back(current.first);
    answer.push_back(current.second);
    return answer;
}
