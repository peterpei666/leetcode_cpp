#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long long> countOfPairs(int n, int x, int y)
    {
        vector<long long> list(n,0);
        if(x>y)
        {
            swap(x,y);
        }
        for(int i=1;i<=n;i++)
        {
            list[0]+=2;
            list[min(i-1,abs(i-y)+x)]--;
            list[min(n-i,abs(i-x)+n-y+1)]--;
            list[min(abs(i-x),abs(i-y)+1)]++;
            list[min(abs(i-x)+1,abs(i-y))]++;
            int temp=max(x-i,0)+max(i-y,0);
            list[temp+(y-x)/2]--;
            list[temp+(y-x+1)/2]--;
        }
        for(int i=1;i<n;i++)
        {
            list[i]+=list[i-1];
        }
        return list;
    }
};
