// Date: 2026-05-21
// https://school.programmers.co.kr/learn/courses/30/lessons/62048

using namespace std;

int getGCD(int a, int b) 
{
    if (b == 0) return a;
    return getGCD(b, a % b);
}

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    int gcd = getGCD(w, h);
    
    long long wrong_square = ((long long)w + h - gcd);
    
    return answer - wrong_square;
}
