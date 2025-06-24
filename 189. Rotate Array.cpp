#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int n=(int)nums.size();
        k%=n;
        if(k==0)
        {
            return;
        }
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            ret[(i+k)%n]=nums[i];
        }
        nums=ret;
    }
};
