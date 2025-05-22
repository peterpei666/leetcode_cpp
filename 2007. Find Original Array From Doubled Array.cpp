#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        if(changed.size()%2)
        {
            return {};
        }
        unordered_map<int,int> list;
        sort(changed.begin(),changed.end());
        for(int i:changed)
        {
            list[i]++;
        }
        vector<int> ret;
        for(int i:changed)
        {
            if(list[i]==0)
            {
                continue;
            }
            if(list[2*i]==0)
            {
                return {};
            }
            ret.push_back(i);
            list[i]--;
            list[2*i]--;
        }
        return ret;
    }
};
