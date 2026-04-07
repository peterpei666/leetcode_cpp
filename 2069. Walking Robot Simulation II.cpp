#include <iostream>
#include <algorithm>
using namespace std;

class Robot
{
private:
    int c;
    int d;
    string direction[4] = {"East", "North", "West", "South"};
    int w, h;
    int x, y;
    
    public:
    Robot(int width, int height)
    {
        c = 2 * (width + height - 2);
        w = width;
        h = height;
        d = 0;
        x = 0;
        y = 0;
    }
    
    void step(int num)
    {
        if (c == 0)
        {
            return;
        }
        num %= c;
        if (num == 0 && (x != 0 || y != 0))
        {
            return;
        }
        if (num == 0 && x == 0 && y == 0)
        {
            d = 3;
            return;
        }
        while (num > 0)
        {
            if (d == 0)
            {
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0)
                {
                    d = 1;
                }
            }
            else if (d == 1)
            {
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0)
                {
                    d = 2;
                }
            }
            else if (d == 2)
            {
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0)
                {
                    d = 3;
                }
            }
            else
            {
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0)
                {
                    d = 0;
                }
            }
        }
    }

    
    vector<int> getPos()
    {
        return {x, y};
    }
    
    string getDir()
    {
        return direction[d];
    }
};
