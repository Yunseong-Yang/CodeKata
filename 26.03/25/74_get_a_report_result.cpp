// https://school.programmers.co.kr/learn/courses/30/lessons/92334

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> list;
    unordered_map<string, int> mail_cnt;
    
    for (const string& p : report){
        stringstream ss(p);
        string user_id, report_id;
        ss >> user_id >> report_id;
        
        list[report_id].insert(user_id); 
    }
    
    for (const string& id : id_list){ 
        auto& reported_id = list[id];
        if (reported_id.size() >= k){
            for (const auto& user : reported_id){
                mail_cnt[user]++;
            }
        }
    }
    
    for (int i = 0; i < id_list.size(); i++){
        answer.push_back(mail_cnt[id_list[i]]);
    }
    
    return answer;
}
