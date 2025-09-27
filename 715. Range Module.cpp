#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class RangeModule
{
private:
    set<pair<int, int>> mp;
    
public:
    RangeModule() {}
    
    void addRange(int left, int right)
    {
        auto it = mp.lower_bound({left, 0});
        if (it != mp.begin() && prev(it)->second >= left)
        {
            it--;
        }
        while (it != mp.end() && it->first <= right)
        {
            left = min(left, it->first);
            right = max(right, it->second);
            it = mp.erase(it);
        }
        mp.insert({left, right});
    }
    
    bool queryRange(int left, int right)
    {
        auto it = mp.upper_bound({left, INT_MAX});
        if (it == mp.begin())
        {
            return false;
        }
        it--;
        return it->first <= left && it->second >= right;
    }
    
    void removeRange(int left, int right)
    {
        auto it = mp.lower_bound({left, 0});
        if (it != mp.begin() && prev(it)->second > left)
        {
            it--;
        }
        vector<pair<int, int>> temp;
        while (it != mp.end() && it->first < right)
        {
            if (it->first < left)
            {
                temp.push_back({it->first, left});
            }
            if (it->second > right)
            {
                temp.push_back({right, it->second});
            }
            it = mp.erase(it);
        }
        for (auto& t : temp)
        {
            mp.insert(t);
        }
    }
};
