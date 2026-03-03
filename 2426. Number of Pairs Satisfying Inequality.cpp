#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int tree[50005];
    int MAX = 50001;
    
    void update(int i)
    {
        for (; i < MAX; i += i & -i)
        {
            tree[i]++;
        }
    }
    
    int query(int i)
    {
        int ans = 0;
        for (; i > 0; i -= i & -i)
        {
            ans += tree[i];
        }
        return ans;
    }
    
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff)
    {
        memset(tree, 0, sizeof(tree));
        int n = (int)nums1.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int t = nums1[i] - nums2[i] + 20001;
            ans += query(t + diff);
            update(t);
        }
        return ans;
    }
};
