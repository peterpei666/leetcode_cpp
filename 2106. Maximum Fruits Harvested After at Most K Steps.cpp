#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)
    {
        int l=0,r=0;
        int n=(int)fruits.size();
        int temp=0,ans=0;
        
        function<int(int,int)> step=[&](int l,int r) -> int
        {
            if(fruits[r][0]<=startPos)
            {
                return startPos-fruits[l][0];
            }
            else if(fruits[l][0]>=startPos)
            {
                return fruits[r][0]-startPos;
            }
            else
            {
                return min(abs(startPos-fruits[r][0]),abs(startPos-fruits[l][0]))+fruits[r][0]-fruits[l][0];
            }
        };
        
        while(r<n)
        {
            temp+=fruits[r][1];
            while(l<=r&&step(l,r)>k)
            {
                temp-=fruits[l][1];
                l++;
            }
            ans=max(ans,temp);
            r++;
        }
        return ans;
    }
};
