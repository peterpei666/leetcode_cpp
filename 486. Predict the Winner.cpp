#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int dfs(vector<int>& nums,int i,int j)
    {
        if(i==j)
        {
            return nums[i];
        }
        int sum1=nums[i]-dfs(nums,i+1,j);
        int sum2=nums[j]-dfs(nums,i,j-1);
        return max(sum1,sum2);
    }
    
public:
    bool predictTheWinner(vector<int>& nums)
    {
        return dfs(nums,0,(int)nums.size()-1)>=0;
    }
};
