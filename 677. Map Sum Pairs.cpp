#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class MapSum
{
public:
    unordered_map<string,int> mp;
    
    MapSum()
    {
        
    }
    
    void insert(const string& key, int val)
    {
        mp[key]=val;
    }
    
    int sum(const string& prefix)
    {
        int n=(int)prefix.size();
        int sum=0;
        for(auto& [s,val]:mp)
        {
            if(s.starts_with(prefix))
            {
                sum+=val;
            }
        }
        return sum;
    }
};
