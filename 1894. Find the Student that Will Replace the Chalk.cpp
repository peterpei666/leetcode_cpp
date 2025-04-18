#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        int sum=0,t=0,n=(int)chalk.size();
        for(int i=0;i<n;i++)
        {
            sum+=chalk[i];
            if(sum>k)
            {
                break;
            }
        }
        k%=sum;
        for(int i=0;i<n;i++)
        {
            if(k>=chalk[i])
            {
                k-=chalk[i];
            }
            else
            {
                t=i;
                break;
            }
        }
        return t;
    }
};
