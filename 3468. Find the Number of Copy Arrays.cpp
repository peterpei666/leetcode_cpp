#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds)
    {
        int n=(int)original.size();
        int m1=bounds[0][0];
        int m2=bounds[0][1];
        for(int i=1;i<n;i++)
        {
            m1=m1+original[i]-original[i-1];
            m2=m2+original[i]-original[i-1];
            m1=max(m1,bounds[i][0]);
            m2=min(m2,bounds[i][1]);
            if(m1>m2)
            {
                return 0;
            }
        }
        return m2-m1+1;
    }
};
