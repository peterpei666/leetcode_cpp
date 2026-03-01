#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        int n = (int)citations.size();
        sort(citations.begin(), citations.end(), greater<>());
        int ans = citations[0];
        for (int i = 0; ans > i; ans--)
        {
            while (i < n && citations[i] >= ans)
            {
                i++;
            }
            if (ans <= i)
            {
                break;
            }
        }
        return ans;
    }
};
