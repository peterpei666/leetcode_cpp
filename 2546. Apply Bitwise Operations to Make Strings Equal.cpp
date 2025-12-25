#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool makeStringsEqual(const string& s, const string& target)
    {
        if (s == target)
        {
            return true;
        }
        int n = (int)s.size();
        bool a = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                a = false;
                break;
            }
        }
        bool b = true;
        for (int i = 0; i < n; i++)
        {
            if (target[i] == '1')
            {
                b = false;
                break;
            }
        }
        return !(a ^ b);
    }
};
