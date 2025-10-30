#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int>& target)
    {
        int n = (int)target.size();
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            if (!stk.empty() && stk.top() >= target[i])
            {
                ans += stk.top() - target[i];
            }
            while (!stk.empty() && stk.top() >= target[i])
            {
                stk.pop();
            }
            stk.push(target[i]);
        }
        return ans + stk.top();
    }
};
