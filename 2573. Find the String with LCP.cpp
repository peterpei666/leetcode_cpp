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

    inline bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    inline int get_count() const
    {
        return count;
    }
};

class Solution
{
public:
    string findTheString(vector<vector<int>>& lcp)
    {
        int n = (int)lcp.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++)
        {
            if (lcp[i][i] != n - i)
            {
                return "";
            }
            for (int j = i + 1; j < n; j++)
            {
                if (lcp[i][j])
                {
                    dsu.unite(i, j);
                }
            }
        }
        if (dsu.get_count() > 26)
        {
            return "";
        }
        string s(n, 0);
        char cur = 'a';
        for (int i = 0; i < n; i++)
        {
            int parent = dsu.find(i);
            if (s[parent] == 0)
            {
                s[parent] = cur;
                cur++;
            }
            s[i] = s[parent];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int x = lcp[i][j];
                if (x != lcp[j][i] || x + i > n)
                {
                    return "";
                }
                int y = (i < n - 1) ? lcp[i + 1][j + 1] : 0;
                y = (s[i] == s[j]) ? y + 1 : 0;
                if (x != y)
                {
                    return "";
                }
            }
        }
        return s;
    }
};
