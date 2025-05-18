#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string maxValue(string& n, int x)
    {
        char c=x+'0';
        int l=(int)n.size();
        if(n[0]=='-')
        {
            int i=1;
            while(i<l&&n[i]<=c)
            {
                i++;
            }
            n.insert(i,1,c);
        }
        else
        {
            int i=0;
            while(i<l&&n[i]>=c)
            {
                i++;
            }
            n.insert(i,1,c);
        }
        return n;
    }
};
