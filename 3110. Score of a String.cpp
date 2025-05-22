#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int len=(int)s.size();
        int score=0;
        for(int i=1;i<len;i++)
        {
            score+=abs(s[i]-s[i-1]);
        }
        return score;
    }
};
