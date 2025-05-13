#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x)
    {
        vector<int> list;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)
            {
                list.push_back(i);
            }
        }
        n=(int)queries.size();
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            if(queries[i]>list.size())
            {
                ret[i]=-1;
            }
            else
            {
                ret[i]=list[queries[i]-1];
            }
        }
        return ret;
    }
};
