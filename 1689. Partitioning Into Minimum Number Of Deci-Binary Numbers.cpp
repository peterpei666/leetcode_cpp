#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPartitions(const string& num)
    {
        int n = (int)num.size();
        char ans = '0';
        for (int i = 0; i < n; i++)
        {
            if (num[i] > ans)
            {
                ans = num[i];
            }
        }
        return ans - '0';
    }
};
