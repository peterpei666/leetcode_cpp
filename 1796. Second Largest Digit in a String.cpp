#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int secondHighest(string& s)
    {
        int m1=-1,m2=-1;
        for(char c:s)
        {
            if(c>='0'&&c<='9')
            {
                if(c-'0'>m1)
                {
                    m2=m1;
                    m1=c-'0';
                }
                else if(c-'0'!=m1&&c-'0'>m2)
                {
                    m2=c-'0';
                }
            }
        }
        return m2;
    }
};
