#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double sq = sqrt(n);
    if (sq != (int)(sq))
    {
        return -1;
    } else
    {
        return pow((int)(sq) + 1, 2);
    }
}
