#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x=0,y=0;
        for(char d:moves)
        {
            switch (d)
            {
                case 'D':
                    y--;
                    break;
                case 'U':
                    y++;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
        }
        return x==0&&y==0;
    }
};
