// Date: 2026-06-17
// BOJ 3197

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected_chicken;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int city_dist = 999999;

void calculate_distance()
{
    int total = 0;
    for (int i = 0; i < house.size(); ++i)
    {
        int min_dist = 999999;
        for (int j = 0; j < selected_chicken.size(); ++j)
        {
            int dist = abs(house[i].first - selected_chicken[j].first)
                + abs(house[i].second - selected_chicken[j].second);

            min_dist = min(min_dist, dist);
        }
        total += min_dist;
    }

    city_dist = min(city_dist, total);
}

void select(int index, int depth) {
    if (depth == m) 
    {
        calculate_distance();
        return;
    }

    for (int i = index; i < chicken.size(); ++i) 
    {
        selected_chicken.push_back(chicken[i]);
        select(i + 1, depth + 1);
        selected_chicken.pop_back();
    }
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a;
            cin >> a;

            v[i].push_back(a);

            if (a == 1)
            {
                house.push_back({ i, j });
            }

            if (a == 2)
            {
                chicken.push_back({ i, j });
            }
        }
    }

    select(0, 0);

    cout << city_dist;

    return 0;
}
