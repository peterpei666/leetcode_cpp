#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2)
    {
        int m=(int)list1.size();
        int n=(int)list2.size();
        vector<vector<int>> ret;
        int i=0,j=0;
        while(i<m&&j<n)
        {
            int l=max(list1[i][0],list2[j][0]);
            int r=min(list1[i][1],list2[j][1]);
            if(l<=r)
            {
                ret.push_back({l,r});
            }
            if(list1[i][1]<list2[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ret;
    }
};
