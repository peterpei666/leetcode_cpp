#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class segment_tree
{
private:
    int n;
    vector<int> tree;
    vector<int> lazy;
    
    int merge(int l, int r)
    {
        return max(l, r);
    }
    
    void build_tree(vector<int>& nums, int s, int e, int node)
    {
        if (s == e)
        {
            tree[node] = nums[s];
            return;
        }
        int mid = (s + e) / 2;
        build_tree(nums, s, mid, 2 * node);
        build_tree(nums, mid + 1, e, 2 * node + 1);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    void push_lazy(int s, int e, int node)
    {
        if (lazy[node] != 0)
        {
            tree[node] = max(tree[node], lazy[node]);
            if (s != e)
            {
                lazy[2 * node] = max(lazy[2 * node], lazy[node]);
                lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
            }
            lazy[node] = 0;
        }
    }
    
    int range_query(int s, int e, int node, int l, int r)
    {
        push_lazy(s, e, node);
        if (r < s || e < l)
        {
            return INT_MIN;
        }
        if (l <= s && e <= r)
        {
            return tree[node];
        }
        int mid = (s + e) / 2;
        int left = range_query(s, mid, 2 * node, l, r);
        int right = range_query(mid + 1, e, 2 * node + 1, l, r);
        return merge(left, right);
    }
    
    void range_update(int s, int e,int node, int l, int r, int val)
    {
        push_lazy(s, e, node);
        if (r < s || e < l)
        {
            return;
        }
        if (l <= s && e <= r)
        {
            lazy[node] = max(val, lazy[node]);
            push_lazy(s, e, node);
            return;
        }
        int mid = (s + e) / 2;
        range_update(s, mid, 2 * node, l, r, val);
        range_update(mid + 1, e, 2 * node + 1, l, r, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    void update_tree(int s, int e, int node, int idx, int val)
    {
        push_lazy(s, e, node);
        if (s == e)
        {
            tree[node] = val;
            return;
        }
        int mid = (s + e) / 2;
        if (idx <= mid)
        {
            update_tree(s, mid, 2 * node, idx, val);
        }
        else
        {
            update_tree(mid + 1, e, 2 * node + 1, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
public:
    segment_tree(vector<int>& nums)
    {
        n = (int)nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build_tree(nums, 0, n - 1, 1);
    }
    
    int query(int l, int r)
    {
        return range_query(0, n - 1, 1, l, r);
    }
    
    void update(int idx, int val)
    {
        update_tree(0, n - 1, 1, idx, val);
    }
    
    void range_update(int l ,int r, int val)
    {
        range_update(0, n - 1, 1, l, r, val);
    }
};


class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>>& positions)
    {
        set<int> corr;
        for (auto& pos : positions)
        {
            corr.insert(pos[0]);
            corr.insert(pos[0] + pos[1] - 1);
        }
        unordered_map<int, int> mp;
        int idx = 0;
        for (int x : corr)
        {
            mp[x] = idx++;
        }
        vector<int> init(idx, 0);
        segment_tree st = segment_tree(init);
        vector<int> ans;
        int mx = 0;
        for (auto& sq : positions)
        {
            int l = mp[sq[0]];
            int r = mp[sq[0] + sq[1] - 1];
            int h = sq[1];
            int base = st.query(l, r);
            st.range_update(l, r, base + h);
            mx = max(mx, st.query(0, idx - 1));
            ans.push_back(mx);
        }
        return ans;
    }
};
