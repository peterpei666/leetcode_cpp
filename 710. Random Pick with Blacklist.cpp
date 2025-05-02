#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;

class Solution
{
public:
    int sz;
    unordered_map<int,int> map;
    mt19937 rng{random_device{}()};
    Solution(int n, vector<int>& blacklist)
    {
        sz=n-(int)blacklist.size();
        unordered_set<int> list(blacklist.begin(),blacklist.end());
        int last=n-1;
        for(int i:blacklist)
        {
            if(i<sz)
            {
                while(list.count(last))
                {
                    last--;
                }
                map[i]=last;
                last--;
            }
        }
    }
    
    int pick()
    {
        int x=rng()%sz;
        if(map.count(x))
        {
            return map[x];
        }
        return x;
    }
};
