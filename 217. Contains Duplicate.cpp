#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> find;
        for(int i:nums)
        {
            if(find.count(i))
            {
                return true;
            }
            find.insert(i);
        }
        return false;
    }
};
