#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinMoves(vector<int>& machines)
    {
        int sum = 0;
        int n = (int)machines.size();
        for (int i = 0; i < n; i++)
        {
            sum += machines[i];
        }
        if (sum % n)
        {
            return -1;
        }
        sum /= n;
        int bal = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int dif = machines[i] - sum;
            bal += dif;
            ans = max(ans, max(abs(bal), dif));
        }
        return ans;
    }
};
