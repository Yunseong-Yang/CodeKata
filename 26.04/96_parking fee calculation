// https://school.programmers.co.kr/learn/courses/30/lessons/92341
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, int> sub_time;
    unordered_map<string, int> result;
    set<string> car_numbers;
    
    for (int i = 0; i < records.size(); i++)
    {
        int hour = stoi(records[i].substr(0, 2));
        int minute = stoi(records[i].substr(3, 2));
        string car_number = records[i].substr(6, 4);
        string state = records[i].substr(11);
        car_numbers.insert(car_number);
        
        if (state == "IN")
        {
            sub_time[car_number] = hour * 60 + minute;
        }
        else if (state == "OUT")
        {
            int calculated_time = hour * 60 + minute - sub_time[car_number];
            result[car_number] = result[car_number] + calculated_time;
            sub_time[car_number] = -1;
        }
    }
    
    for (const string& number : car_numbers)
    {
        if (sub_time[number] != -1)
        {
            result[number] += 23 * 60 + 59 - sub_time[number];
        }
    }
    
    for (const string& number : car_numbers)
    {
        if (result[number] <= fees[0])
        {
            answer.push_back(fees[1]);
            continue;
        }
        
        answer.push_back(fees[1] + (ceil(((double)result[number] - fees[0]) / fees[2])) * fees[3]);
    }
    
    return answer;
}
