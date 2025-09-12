#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool doesAliceWin(const string& s)
    {
        int n = (int)s.size();
        char vowel[] = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (s[i] == vowel[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
