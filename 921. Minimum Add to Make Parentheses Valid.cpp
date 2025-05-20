#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string& s)
    {
        int ans=0,count=0;
        for(char c:s)
        {
            switch(c)
            {
                case '(':
                    count++;
                    break;
                case ')':
                    if(count==0)
                    {
                        ans++;
                    }
                    else
                    {
                        count--;
                    }
                    break;
            }
        }
        return ans+count;
    }
};
