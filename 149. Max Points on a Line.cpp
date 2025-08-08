#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline bool line(vector<int>& a,vector<int>& b,vector<int>& p)
    {
        return (a[1]-p[1])*(b[0]-p[0])==(a[0]-p[0])*(b[1]-p[1]);
    }
    
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n=(int)points.size();
        int ans=min(2,n);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp=2;
                for(int k=0;k<n;k++)
                {
                    if(k==i||k==j)
                    {
                        continue;
                    }
                    if(line(points[i],points[j],points[k]))
                    {
                        temp++;
                    }
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
