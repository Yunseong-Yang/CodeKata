// https://school.programmers.co.kr/learn/courses/30/lessons/92335

#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    stack<int> st;
    while(n != 0)
    {
        int num = n % k;
        st.push(num);
        n /= k;
    }
    
    string str = "";
    while(!st.empty())
    {
        int num = st.top();
        st.pop();
        if (num != 0)
        {
            str += to_string(num);
        }
        else
        {
            if (str == "")
            {
                continue;
            }
            long long p = stoll(str);
            if (isPrime(p))
            {
                answer++;
            }
            str = "";
        }
    }

    if (str.size() != 0)
    {
        long long p = stoll(str);
        if (isPrime(p))
        {
            answer++;
        }
        str = "";
    }

    return answer;
}
