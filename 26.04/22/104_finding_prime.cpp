// https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

set<string> results;

int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return n;
}

void DFS(string str, const string& numbers, vector<bool>& visited)
{
    if (!str.empty())
    {
        results.insert(str);
    }
    
    if (str.size() == numbers.size())
    {
        return;
    }
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            DFS(str + numbers[i], numbers, visited);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int cnt = 0;
    vector<bool> visited(numbers.size(), false);
    
    DFS("", numbers, visited);
    set<int> intResults;
    
    for (string s : results)
    {
        intResults.insert(stoi(s));
    }
    
    for (int s : intResults)
    {
        int n = isPrime(s);
        if (n != 0)
        {
            cnt++;
        }
    }
    
    return cnt;
}
