#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        unordered_set<int> ans;
        unordered_set<int> cur;
        for(int x:arr)
        {
            unordered_set<int> next;
            next.insert(x);
            for(int y:cur)
            {
                next.insert(x|y);
            }
            ans.insert(next.begin(),next.end());
            cur=next;
        }
        return (int)ans.size();
    }
};
