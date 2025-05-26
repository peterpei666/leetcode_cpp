#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int flipLights(int n, int presses)
    {
        unordered_set<int> found;
        for(int mask=0;mask<16;mask++)
        {
            int b1=(mask>>0)&1;
            int b2=(mask>>1)&1;
            int b3=(mask>>2)&1;
            int b4=(mask>>3)&1;
            int total=b1+b2+b3+b4;
            if(total%2!=presses%2||total>presses)
            {
                continue;
            }
            int state=0;
            for(int i=0;i<min(n,3);i++)
            {
                int l=1;
                if(b1)
                {
                    l^=1;
                }
                if(b2&&i%2==1)
                {
                    l^=1;
                }
                if(b3&&i%2==0)
                {
                    l^=1;
                }
                if(b4&&i%3==0)
                {
                    l^=1;
                }
                state<<=1;
                state+=l;
            }
            found.insert(state);
        }
        return (int)found.size();
    }
};
