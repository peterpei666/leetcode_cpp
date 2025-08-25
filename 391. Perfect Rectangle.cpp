#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>>& rectangles)
    {
        unordered_map<long long,int> mp;
        const long long M=1e6;
        for(auto& rec:rectangles)
        {
            mp[rec[0]*M+rec[1]]++;
            mp[rec[0]*M+rec[3]]--;
            mp[rec[2]*M+rec[1]]--;
            mp[rec[2]*M+rec[3]]++;
        }
        int cnt=0;
        for(auto [_,x]:mp)
        {
            if(x)
            {
                if(abs(x)!=1)
                {
                    return false;
                }
                cnt++;
            }
        }
    return cnt==4;
    }
};
