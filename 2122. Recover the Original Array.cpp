#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> recoverArray(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            int k=nums[i]-nums[0];
            if(k==0||k&1)
            {
                continue;
            }
            k/=2;
            multiset<int> m(nums.begin(),nums.end());
            vector<int> res;
            while(!m.empty())
            {
                int low=*m.begin();
                m.erase(m.begin());
                int high=low+2*k;
                auto f=m.find(high);
                if(f==m.end())
                {
                    break;
                }
                m.erase(f);
                res.push_back(low+k);
            }
            if(res.size()==nums.size()/2)
            {
                return res;
            }
        }
        return {};
    }
};
