#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int>& nums, int value)
    {
        unordered_map<int,int> list;
        for(int i:nums)
        {
            list[(i%value+value)%value]++;
        }
        int mex=0;
        while(list[mex%value])
        {
            list[mex%value]--;
            mex++;
        }
        return mex;
    }
};
