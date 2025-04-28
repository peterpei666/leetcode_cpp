#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortEvenOdd(vector<int>& nums)
    {
        int odd=(int)nums.size()/2;
        int even=(int)nums.size()-odd;
        vector<int> list1(odd);
        vector<int> list2(even);
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
            {
                list1[i>>1]=nums[i];
            }
            else
            {
                list2[i>>1]=nums[i];
            }
        }
        sort(list2.begin(),list2.end());
        sort(list1.begin(),list1.end(),greater<int>());
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
            {
                nums[i]=list1[i>>1];
            }
            else
            {
                nums[i]=list2[i>>1];
            }
        }
        return nums;
    }
};
