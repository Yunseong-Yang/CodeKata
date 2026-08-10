#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    int a, b;
    int cnt = 0;
    bool flag = 0;

    cin >> a >> b;

    while (true)
    {
        if (a > b)
        {
            flag = 1;
            break;
        }
        else if (a == b)
        {
            break;
        }

        if (b % 2 == 0)
        {
            b /= 2;
            cnt++;
        }
        else
        {
            if (b % 10 == 1)
            {
                cnt++;
                b /= 10;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
    {
        cout << -1;
    }
    else
    {
        cout << cnt + 1;
    }

    return 0;
}
