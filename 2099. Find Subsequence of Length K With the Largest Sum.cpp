#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        int n=(int)nums.size();
        pair<int,int> list[n];
        for(int i=0;i<n;i++)
        {
            list[i]={nums[i],i};
        }
        sort(&list[0],&list[0]+n,greater<>());
        sort(&list[0],&list[0]+k,[&](pair<int,int>& a,pair<int,int>& b) { return a.second<b.second; });
        vector<int> ret(k);
        for(int i=0;i<k;i++)
        {
            ret[i]=list[i].first;
        }
        return ret;
    }
};
