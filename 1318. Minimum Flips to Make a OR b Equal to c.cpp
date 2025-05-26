#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int count=0;
        while(c||(a|b))
        {
            int temp=a|b;
            if((c&1)==1&&(temp&1)==0)
            {
                count++;
            }
            else if((c&1)==0&&(temp&1)==1)
            {
                count+=(a&1)+(b&1);
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return count;
    }
};
