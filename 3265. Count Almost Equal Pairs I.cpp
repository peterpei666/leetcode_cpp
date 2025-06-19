#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool valid(int a,int b)
    {
        if(a==b)
        {
            return true;
        }
        int list1[10]={0};
        int list2[10]={0};
        int cnt=0;
        while(a||b)
        {
            int temp1=a%10;
            int temp2=b%10;
            if(temp1!=temp2)
            {
                cnt++;
                if(cnt>2)
                {
                    return false;
                }
            }
            list1[temp1]++;
            list2[temp2]++;
            a/=10;
            b/=10;
        }
        if(cnt==2&&memcmp(list1+1,list2+1,sizeof(int)*9)==0)
        {
            return true;
        }
        return false;
    }
    
public:
    int countPairs(vector<int>& nums)
    {
        int n=(int)nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(valid(nums[i],nums[j]))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
