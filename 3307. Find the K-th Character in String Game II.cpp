#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    char kthCharacter(long long k, vector<int>& operations)
    {
        int ans=0;
        while(k!=1)
        {
            int temp=log2(k);
            if((1LL<<temp)==k)
            {
                temp--;
            }
            k-=1LL<<temp;
            if(operations[temp])
            {
                ans++;
            }
        }
        return 'a'+(ans%26);
    }
};
