#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    long long C[51][51];
    
public:
    Solution()
    {
        for (int i = 0; i <= 50; i++)
        {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    
    long long nthSmallest(long long n, int k)
    {
        long long ans = 0;
        for (int i = 49; i >= 0; i--)
        {
            if (n > C[i][k])
            {
                n -= C[i][k];
                k--;
                ans |= 1LL << i;
                if (k == 0)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
