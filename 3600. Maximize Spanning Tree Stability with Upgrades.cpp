#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    DSU(int n) : parent(n), rank(n, 0), count(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
            return true;
        }
        return false;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    int get_count() const
    {
        return count;
    }
};

class Solution
{
private:
    bool check(int n, vector<vector<int>>& edges, int k, int x)
    {
        DSU dsu(n);
        for (auto& e : edges)
        {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must)
            {
                if (s < x)
                {
                    return false;
                }
                if (!dsu.unite(u, v))
                {
                    return false;
                }
            }
        }
        for (auto& e : edges)
        {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 0 && s >= x)
            {
                dsu.unite(u, v);
            }
        }
        int used = 0;
        for (auto& e : edges)
        {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 0 && s < x && 2 * s >= x)
            {
                if (dsu.unite(u, v))
                {
                    used++;
                    if (used > k)
                    {
                        return false;
                    }
                }
            }
        }
        return dsu.get_count() == 1;
    }
    
public:
    int maxStability(int n, vector<vector<int>>& edges, int k)
    {
        DSU dsu(n);
        for (auto& e : edges)
        {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must && !dsu.unite(u, v))
            {
                return -1;
            }
        }
        int l = 1, r = 200000;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(n, edges, k, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
