#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPalindrome(const string& s)
    {
        char t[200000];
        int i = 0, k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                t[k] = s[i] - 'A' + 'a';
                k++;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                t[k] = s[i];
                k++;
            }
        }
        int l = 0, r = k - 1;
        while (l < r)
        {
            if (t[l] != t[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
