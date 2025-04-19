#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t)
    {
        vector<int> list(26);
        int sz=(int)s.size();
        for(int i=0;i<sz;i++)
        {
            list[s[i]-'a']=i;
        }
        int dif=0;
        for(int i=0;i<sz;i++)
        {
            dif+=abs(i-list[t[i]-'a']);
        }
        return dif;
    }
};
