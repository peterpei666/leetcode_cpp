#include <iostream>
#include <algorithm>
using namespace std;

class RandomizedCollection
{
private:
    vector<int> nums;
    unordered_map<int,vector<int>> mp;
    vector<int> pos;
    
public:
    RandomizedCollection()
    {
        srand((unsigned int)time(nullptr));
    }
    
    bool insert(int val)
    {
        bool ans=mp[val].empty();
        nums.push_back(val);
        mp[val].push_back((int)nums.size()-1);
        pos.push_back((int)mp[val].size()-1);
        return ans;
    }
    
    bool remove(int val)
    {
        if(mp[val].empty())
        {
            return false;
        }
        int target=mp[val].back();
        mp[val].pop_back();
        int last=(int)nums.size()-1;
        if(target!=last)
        {
            int val=nums[last];
            nums[target]=val;
            int idx=pos[last];
            mp[val][idx]=target;
            pos[target]=idx;
        }
        nums.pop_back();
        pos.pop_back();
        return true;
    }
    
    int getRandom()
    {
        return nums[rand()%nums.size()];
    }
};
