#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const double dif=1e-6;
    
    inline vector<double> compute(double a,double b)
    {
        vector<double> ans={a+b,a-b,b-a,a*b};
        if(a>dif) ans.push_back(b/a);
        if(b>dif) ans.push_back(a/b);
        return ans;
    }
    
    bool dfs(vector<double>& nums)
    {
        int n=(int)nums.size();
        if(n==1)
        {
            return fabs(nums[0]-24.0)<dif;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                vector<double> next;
                for(int k=0;k<n;k++)
                {
                    if(k!=i&&k!=j)
                    {
                        next.push_back(nums[k]);
                    }
                }
                for(double val:compute(nums[i],nums[j]))
                {
                    next.push_back(val);
                    if(dfs(next))
                    {
                        return true;
                    }
                    next.pop_back();
                }
            }
        }
        return false;
    }
    
public:
    bool judgePoint24(vector<int>& cards)
    {
        int n=(int)cards.size();
        vector<double> nums(n);
        for(int i=0;i<n;i++)
        {
            nums[i]=(double)cards[i];
        }
        return dfs(nums);
    }
};
