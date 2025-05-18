#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxPalindromesAfterOperations(vector<string>& words)
    {
        int n=(int)words.size();
        int pair=0;
        int odd=0;
        int len[n];
        for(int i=0;i<n;i++)
        {
            len[i]=(int)words[i].size();
            for(char c:words[i])
            {
                if(odd&(1<<(c-'a')))
                {
                    pair++;
                }
                odd^=1<<(c-'a');
            }
        }
        sort(&len[0],&len[0]+n);
        for(int i=0;i<n;i++)
        {
            pair-=len[i]/2;
            if(pair<0)
            {
                return i;
            }
        }
        return n;
    }
};
