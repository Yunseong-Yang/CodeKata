// https://school.programmers.co.kr/learn/courses/30/lessons/77885

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
string DecimalToBinary(long long n)
{
    string s = "";
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
        n /= 2;
    }
    s += '0';
    reverse(s.begin(), s.end());
    return s;
}

long long BinaryToDecimal(string s)
{
    long long n = 0;
    long long index = 0;
    for (long long i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            n += pow(2, index);
        }
        index++;
    }
    
    return n;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            answer.push_back(numbers[i] + 1);
        }
        else
        {
            string s = DecimalToBinary(numbers[i]);
            for (long long i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                    s[i + 1] = '0';
                    break;
                }
            }
            answer.push_back(BinaryToDecimal(s));
        }
    }
    
    return answer;
}
