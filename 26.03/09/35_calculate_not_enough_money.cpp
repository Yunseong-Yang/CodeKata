// https://school.programmers.co.kr/learn/courses/30/lessons/82612

using namespace std;

long long solution(int price, int money, int count)
{
    long long current = 0;
    for (int i = 1; i <= count; i++)
    {
        current += price * i;
    }

    return money - current < 0 ? current - money : 0;
}
