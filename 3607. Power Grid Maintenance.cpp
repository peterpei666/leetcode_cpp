#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
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
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        DSU mp(c + 1);
        for (auto& con : connections)
        {
            mp.unite(con[0], con[1]);
        }
        unordered_map<int, set<int>> temp;
        for (int i = 1; i <= c; i++)
        {
            temp[mp.find(i)].insert(i);
        }
        vector<int> ans;
        for (auto& q : queries)
        {
            if (q[0] == 1)
            {
                if (temp[mp.find(q[1])].empty())
                {
                    ans.push_back(-1);
                }
                else if (temp[mp.find(q[1])].count(q[1]))
                {
                    ans.push_back(q[1]);
                }
                else
                {
                    ans.push_back(*temp[mp.find(q[1])].begin());
                }
            }
            else
            {
                temp[mp.find(q[1])].erase(q[1]);
            }
        }
        return ans;
    }
};
