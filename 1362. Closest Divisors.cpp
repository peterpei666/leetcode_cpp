#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> closestDivisors(int num)
    {
        vector<int> ret(2);
        ret[0]=1;
        ret[1]=num+1;
        int dif=num;
        num++;
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0&&abs(i-num/i)<dif)
            {
                dif=abs(i-num/i);
                ret[0]=i;
                ret[1]=num/i;
                if(dif==0)
                {
                    return ret;
                }
            }
        }
        num++;
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0&&abs(i-num/i)<dif)
            {
                dif=abs(i-num/i);
                ret[0]=i;
                ret[1]=num/i;
                if(dif==0)
                {
                    return ret;
                }
            }
        }
        return ret;
    }
};
