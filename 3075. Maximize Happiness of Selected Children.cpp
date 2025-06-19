#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(),happiness.end(),greater<int>());
        int n=(int)happiness.size();
        long long sum=0;
        for(int i=0;i<n&&i<k;i++)
        {
            if(happiness[i]<i)
            {
                break;
            }
            sum+=(long long)happiness[i]-i;
        }
        return sum;
    }
};
