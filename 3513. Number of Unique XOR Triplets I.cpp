#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        int n=(int)nums.size();
        if(n<3)
        {
            return n;
        }
        int cnt=log(n)/log(2);
        return 1<<(cnt+1);
    }
};
