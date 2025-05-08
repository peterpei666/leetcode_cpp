#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int minimizedStringLength(string s)
    {
        bitset<26> find;
        for(char c:s)
        {
            find.set(c-'a');
        }
        return (int)find.count();
    }
};
