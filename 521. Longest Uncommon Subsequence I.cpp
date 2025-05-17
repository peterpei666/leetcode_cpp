#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if(a==b)
        {
            return -1;
        }
        return (int)max(a.size(),b.size());
    }
};
