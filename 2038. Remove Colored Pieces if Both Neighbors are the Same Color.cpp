#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool winnerOfGame(const string& colors)
    {
        int cntA=0,cntB=0;
        int tempA=0,tempB=0;
        for(char c:colors)
        {
            if(c=='A')
            {
                if(tempB>2)
                {
                    cntB+=tempB-2;
                }
                tempB=0;
                tempA++;
            }
            else
            {
                if(tempA>2)
                {
                    cntA+=tempA-2;
                }
                tempA=0;
                tempB++;
            }
        }
        if(tempA>2)
        {
            cntA+=tempA-2;
        }
        if(tempB>2)
        {
            cntB+=tempB-2;
        }
        return cntA>cntB;
    }
};
