#include <iostream>
#include <algorithm>
#include <bitset>
#include <numeric>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> parity;
    
public:
    DSU(int n) : parent(n), rank(n, 0), parity(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    pair<int, int> find(int x)
    {
        if (parent[x] == x)
        {
            return make_pair(x, 0);
        }
        auto [p, o] = find(parent[x]);
        parent[x] = p;
        parity[x] ^= o;
        return make_pair(parent[x], parity[x]);
    }

    bool unite(int x, int y, int w)
    {
        auto [px, ox] = find(x);
        auto [py, oy] = find(y);
        if (px == py)
        {
            return (ox ^ oy) == w;
        }
        if (rank[px] > rank[py])
        {
            parent[py] = px;
            parity[py] = ox ^ oy ^ w;
        }
        else if (rank[px] < rank[py])
        {
            parent[px] = py;
            parity[px] = ox ^ oy ^ w;
        }
        else
        {
            parent[py] = px;
            parity[py] = ox ^ oy ^ w;
            rank[px]++;
        }
        return true;
    }
};

class Solution
{
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges)
    {
        int ans = 0;
        DSU dsu(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dsu.unite(u, v, w))
            {
                ans++;
            }
        }
        return ans;
    }
};
