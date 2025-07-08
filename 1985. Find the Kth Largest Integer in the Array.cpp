#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string kthLargestNumber(vector<string>& nums, int k)
    {
        sort(nums.begin(),nums.end(),[&](const string& a,const string& b) { if(a.size()!=b.size()) return a.size()>b.size(); return a>b; });
        return nums[k-1];
    }
};
