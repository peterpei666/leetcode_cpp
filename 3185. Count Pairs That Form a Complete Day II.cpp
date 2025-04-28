#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countCompleteDayPairs(vector<int>& hours)
    {
        int list[24]={0};
        for(int t:hours)
        {
            list[t%24]++;
        }
        long long ans=0;
        ans+=(long long)list[0]*(long long)(list[0]-1)/2;
        ans+=(long long)list[12]*(long long)(list[12]-1)/2;
        for(int i=1;i<12;i++)
        {
            ans+=(long long)list[i]*(long long)list[24-i];
        }
        return ans;
    }
};
