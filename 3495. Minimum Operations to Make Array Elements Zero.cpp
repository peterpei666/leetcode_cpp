#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long count(int x)
    {
        if(x==0)
        {
            return 0;
        }
        int n=-1,t=x;
        while(t)
        {
            t>>=2;
            n++;
        }
        long long ret=(long long)x*(n+1);
        long long cur=1<<2*n;
        while(cur)
        {
            ret-=cur-1;
            cur>>=2;
        }
        return ret;
    }
    
    long long minOperations(vector<vector<int>>& queries)
    {
        long long ret=0;
        for(auto& v:queries)
        {
            long long temp=count(v[1])-count(v[0]-1);
            ret+=temp/2+temp%2;
        }
        return ret;
    }
};
