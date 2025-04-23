#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right)
    {
        bitset<50> found;
        for(uint8_t m=0;m<ranges.size();m++)
        {
            for(uint8_t i=ranges[m][0];i<=ranges[m][1];i++)
            {
                found.set(i-1);
            }
        }
        bitset<50> target;
        for(uint8_t i=left;i<=right;i++)
        {
            target.set(i-1);
        }
        if((target&found)==target)
        {
            return true;
        }
        return false;
    }
};


