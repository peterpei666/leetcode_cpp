#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> partitionString(const string& s)
    {
        unordered_set<string> mp;
        vector<string> ret;
        string temp;
        for(char c:s)
        {
            temp+=c;
            if(!mp.count(temp))
            {
                mp.insert(temp);
                ret.push_back(temp);
                temp="";
            }
        }
        return ret;
    }
};
