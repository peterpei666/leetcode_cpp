#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinimumTime(vector<int>& strength, int k)
    {
        int ans=INT_MAX;
        sort(strength.begin(),strength.end());
        do
        {
            int temp=1;
            int t=0;
            for(int i:strength)
            {
                t+=(i+temp-1)/temp;
                temp+=k;
            }
            ans=min(ans,t);
        }while(next_permutation(strength.begin(),strength.end()));
        return ans;
    }
};
