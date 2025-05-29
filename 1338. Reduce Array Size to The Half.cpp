#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int>& arr)
    {
        vector<int> cnt(100000,0);
        for(int n:arr)
        {
            cnt[n-1]++;
        }
        sort(cnt.begin(),cnt.end(),greater<int>());
        int n=(int)arr.size();
        n/=2;
        for(int i=0;i<100000;i++)
        {
            n-=cnt[i];
            if(n<=0)
            {
                return i+1;
            }
        }
        return 0;
    }
};
