#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> decimalRepresentation(int n)
    {
        vector<int> ans;
        long long temp = 1;
        while (n)
        {
            if (n % 10)
            {
                ans.push_back((int)(n % 10 * temp));
            }
            n /= 10;
            temp *= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
