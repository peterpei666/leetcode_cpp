#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int partitionString(const string& s)
    {
        int found=0;
        int cnt=1;
        for(char c:s)
        {
            if(found&(1<<(c-'a')))
            {
                found=0;
                cnt++;
            }
            found|=1<<(c-'a');
        }
        return cnt;
    }
};
