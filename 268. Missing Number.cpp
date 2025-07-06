#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        bitset<10001> find;
        for(int i:nums)
        {
            find.set(i);
        }
        for(int i=(int)nums.size();i>0;i--)
        {
            if(find.test(i)==false)
            {
                return i;
            }
        }
        return 0;
    }
};
