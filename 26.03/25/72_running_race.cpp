// https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> ranks;
    
    for (int i = 0; i < players.size(); i++)
    {
        ranks[players[i]] = i;
    }
    
    
    for (int i = 0; i < callings.size(); i++)
    {
        int calling_rank = ranks[callings[i]];
        
        string temp = players[calling_rank - 1];
        players[calling_rank - 1] = callings[i];
        players[calling_rank] = temp;
        
        ranks[players[calling_rank - 1]] = calling_rank - 1;
        ranks[players[calling_rank]] = calling_rank;
    }
    return players;
}
