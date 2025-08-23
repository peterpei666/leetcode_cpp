#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end(),[&](vector<int>& a,vector<int>& b) { return a[0]==b[0]?a[1]>b[1]:a[0]<b[0]; });
        int n=(int)envelopes.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(ans.begin(),ans.end(),envelopes[i][1]);
            if(it==ans.end())
            {
                ans.push_back(envelopes[i][1]);
            }
            else
            {
                *it=envelopes[i][1];
            }
        }
        return (int)ans.size();
    }
};
