#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int count=0,ret=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                count++;
            }
            if(s[i]=='0'&&(i+1>=s.size()||s[i+1]=='1'))
            {
                ret+=count;
            }
        }
        return ret;
    }
};
