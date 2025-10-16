#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minFlips(const string& target)
    {
        int cnt=0;
        for(char c:target)
        {
            if((c-'0')^(cnt&1))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
