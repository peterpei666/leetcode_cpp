#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        int n=(int)nums.size()/3;
        vector<int> ret;
        for(auto m:mp)
        {
            if(m.second>n)
            {
                ret.emplace_back(m.first);
            }
        }
        return ret;
    }
};
