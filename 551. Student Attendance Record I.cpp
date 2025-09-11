#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkRecord(const string& s)
    {
        int a = 0, l = 0;
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                l++;
                if (l == 3)
                {
                    return false;
                }
            }
            else
            {
                l = 0;
            }
            if (s[i] == 'A')
            {
                a++;
            }
        }
        return a < 2;
    }
};
