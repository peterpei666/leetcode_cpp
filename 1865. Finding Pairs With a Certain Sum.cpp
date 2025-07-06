#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class FindSumPairs
{
private:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        arr1=nums1;
        arr2=nums2;
        for(int i:nums1)
        {
            mp1[i]++;
        }
        for(int i:nums2)
        {
            mp2[i]++;
        }
    }
    
    void add(int idx, int val)
    {
        mp2[arr2[idx]]--;
        if(mp2[arr2[idx]]==0)
        {
            mp2.erase(arr2[idx]);
        }
        arr2[idx]+=val;
        mp2[arr2[idx]]++;
    }
    
    int count(int tot)
    {
        int ans=0;
        for(auto& [i,n]:mp1)
        {
            if(mp2.count(tot-i))
            {
                ans+=n*mp2[tot-i];
            }
        }
        return ans;
    }
};
