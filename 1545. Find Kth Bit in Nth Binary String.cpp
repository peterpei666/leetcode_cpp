#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string s="0";
        k--;
        while(s.size()<=k)
        {
            string temp=s;
            for(char& c:temp)
            {
                c=c=='0'?'1':'0';
            }
            reverse(temp.begin(),temp.end());
            s=s+"1"+temp;
        }
        return s[k];
    }
};
