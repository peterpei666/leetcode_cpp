#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if(k>s.size())
        {
            return false;
        }
        bitset<26> count;
        for(char c:s)
        {
            count.flip(c-'a');
        }
        if(count.count()>k)
        {
            return false;
        }
        return true;
    }
};

