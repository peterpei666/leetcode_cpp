#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int n = (int)apple.size();
        int m = (int)capacity.size();
        sort(capacity.begin(), capacity.end(), greater<>());
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += apple[i];
        }
        int ans = 0;
        while (total > 0)
        {
            total -= capacity[ans];
            ans++;
        }
        return ans;
    }
};
