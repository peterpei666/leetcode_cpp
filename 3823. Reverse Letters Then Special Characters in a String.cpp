#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseByType(string s)
    {
        char letter[100];
        char special[100];
        int idx1 = 0, idx2 = 0;
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                letter[idx1++] = s[i];
            }
            else
            {
                special[idx2++] = s[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = letter[--idx1];
            }
            else
            {
                s[i] = special[--idx2];
            }
        }
        return s;
    }
};
