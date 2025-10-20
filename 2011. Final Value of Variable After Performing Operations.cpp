#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int n = (int)operations.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (operations[i][1] == '+')
            {
                ans++;
            }
            else
            {
                ans--;
            }
        }
        return ans;
    }
};
