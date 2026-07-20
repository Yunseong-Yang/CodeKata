#include <iostream>
#include <vector>

using namespace std;

struct shark
{
    shark() 
        : speed(0), dir(0), size(0) {}
    shark(int speed, int dir, int size) 
        : speed(speed), dir(dir), size(size) {}

    int speed;
    int dir;
    int size;
};

int main()
{
    int r, c, m;
    cin >> r >> c >> m;

    vector<vector<shark>> arr(r + 1, vector<shark>(c + 1));

    for (int i = 0; i < m; ++i)
    {
        int a, b, d, e, f;
        cin >> a >> b >> d >> e >> f;
        arr[a][b] = shark(d, e, f);
    }

    int sum = 0;

    for (int col = 1; col <= c; ++col)
    {
        for (int row = 1; row <= r; ++row)
        {
            if (arr[row][col].size > 0)
            {
                sum += arr[row][col].size;
                arr[row][col] = shark();
                break;
            }
        }

        vector<vector<shark>> next(r + 1, vector<shark>(c + 1));

        for (int i = 1; i <= r; ++i)
        {
            for (int j = 1; j <= c; ++j)
            {
                if (arr[i][j].size > 0)
                {
                    shark cur = arr[i][j];
                    int row = i;
                    int col = j;
                    int speed = cur.speed;
                    int dir = cur.dir;

                    if (dir == 1 || dir == 2)
                    {
                        speed %= ((r - 1) * 2);
                    }
                    else
                    {
                        speed %= ((c - 1) * 2);
                    }

                    for (int k = 0; k < speed; ++k)
                    {
                        if (dir == 1) 
                        {
                            if (row == 1) 
                            { 
                                dir = 2; 
                                row++; 
                            }
                            else
                            {
                                row--;
                            }                                
                        }
                        else if (dir == 2) 
                        {
                            if (row == r) 
                            { 
                                dir = 1; 
                                row--; 
                            }
                            else
                            {
                                row++;
                            }
                        }
                        else if (dir == 3) 
                        {
                            if (col == c) 
                            {
                                dir = 4;
                                col--; 
                            }
                            else
                            {
                                col++;
                            }
                        }
                        else if (dir == 4) 
                        {
                            if (col == 1) 
                            { 
                                dir = 3;
                                col++; 
                            }
                            else
                            {
                                col--;
                            }
                        }
                    }

                    if (next[row][col].size < cur.size)
                    {
                        next[row][col] = shark(cur.speed, dir, cur.size);
                    }
                }
            }
        }
        arr = next;
    }

    cout << sum << "\n";

    return 0;
}