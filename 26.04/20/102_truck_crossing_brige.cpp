#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    int index = 0;
    int sum_weights = 0;
    queue<pair<int, int>> q;
    q.push({truck_weights[index], time});
    sum_weights += truck_weights[index];
    index++;
    while (!q.empty())
    {
        time++;
        if (time - q.front().second == bridge_length)
        {
            sum_weights -= q.front().first;
            q.pop();
        }

        if (index < truck_weights.size() && sum_weights + truck_weights[index] <= weight)
        {
            q.push({truck_weights[index], time});
            sum_weights += truck_weights[index];
            index++;
        }
    }
    
    return time;
}
