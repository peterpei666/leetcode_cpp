#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int tree[100005];
    int MAX = 100001;
    
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
    int createSortedArray(vector<int>& instructions)
    {
        memset(tree, 0, sizeof(tree));
        int n = (int)instructions.size();
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int left = query(instructions[i] - 1);
            int right = i - query(instructions[i]);
            ans += min(left, right);
            update(instructions[i]);
        }
        return ans % mod;
    }
};
