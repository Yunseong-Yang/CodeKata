// Date: 2026-05-19
// https://school.programmers.co.kr/learn/courses/30/lessons/135807

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getGCD(int a, int b) 
{
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    
    for (int i = 1; i < arrayA.size(); ++i) 
    {
        gcdA = getGCD(gcdA, arrayA[i]);
        gcdB = getGCD(gcdB, arrayB[i]);
    }
    

    bool isValidA = true;
    for (int num : arrayB) 
    {
        if (num % gcdA == 0) 
        {
            isValidA = false;
            break;
        }
    }
    
    if (isValidA)
    {
        answer = max(answer, gcdA);
    }
    
    bool isValidB = true;
    for (int num : arrayA) 
    {
        if (num % gcdB == 0) 
        {
            isValidB = false;
            break;
        }
    }
    
    if (isValidB)
    {
        answer = max(answer, gcdB);
    }
    
    return answer;
}