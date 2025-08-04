#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        unordered_map<int,int> mp;
        int l=0,ans=0;
        int n=(int)fruits.size();
        for(int i=0;i<n;i++)
        {
            mp[fruits[i]]++;
            while(mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
