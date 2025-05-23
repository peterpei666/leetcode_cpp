#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while(tx>sx&&ty>sy)
        {
            if(tx>ty)
            {
                tx%=ty;
            }
            else
            {
                ty%=tx;
            }
        }
        return (sx==tx&&sy<=ty&&(ty-sy)%sx==0)||(sy==ty&&sx<=tx&&(tx-sx)%sy==0);
    }
};
