#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class RangeFreqQuery
{
public:
    unordered_map<int,vector<int>> list;
    
    RangeFreqQuery(vector<int>& arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            list[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value)
    {
        return (int)(upper_bound(list[value].begin(),list[value].end(),right)-lower_bound(list[value].begin(),list[value].end(),left));
    }
};
