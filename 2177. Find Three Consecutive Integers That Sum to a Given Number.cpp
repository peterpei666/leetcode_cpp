#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> ret;
        if(num%3==0)
        {
            ret.push_back(num/3-1);
            ret.push_back(num/3);
            ret.push_back(num/3+1);
        }
        return ret;
    }
};
