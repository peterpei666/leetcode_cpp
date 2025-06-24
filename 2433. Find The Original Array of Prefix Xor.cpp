#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int>& pref)
    {
        int n=(int)pref.size();
        vector<int> ret(n);
        ret[0]=pref[0];
        for(int i=1;i<n;i++)
        {
            ret[i]=pref[i]^pref[i-1];
        }
        return ret;
    }
};
