#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkTwoChessboards(const string& s1,const string& s2)
    {
        return !((((s1[0]-'a')&1)^((s1[1]-'0')&1))^(((s2[0]-'a')&1)^((s2[1]-'0')&1)));
    }
};
