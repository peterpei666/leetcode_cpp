#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    inline bool prime(int x)
    {
        if(x==2||x==3||x==5||x==7||x==11||x==13||x==17||x==19||x==23||x==29||x==31||x==37||x==41||x==43||x==47||x==53||x==59||x==61||x==67||x==71||x==73||x==79||x==83||x==89||x==97)
        {
            return true;
        }
        return false;
    }
    
public:
    bool checkPrimeFrequency(vector<int>& nums)
    {
        vector<int> list(101,0);
        for(int n:nums)
        {
            list[n]++;
        }
        for(int cnt:list)
        {
            if(cnt==0)
            {
                continue;
            }
            if(prime(cnt))
            {
                return true;
            }
        }
        return false;
    }
};
