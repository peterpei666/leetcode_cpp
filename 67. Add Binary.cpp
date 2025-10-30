#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(const string& a, const string& b)
    {
        int add = 0;
        int m = (int)a.size() - 1;
        int n = (int)b.size() - 1;
        string s = "";
        while (m >= 0 || n >= 0)
        {
            int temp = add;
            if (m >= 0)
            {
                temp += a[m] - '0';
                m--;
            }
            if (n >= 0)
            {
                temp += b[n] - '0';
                n--;
            }
            add = temp / 2;
            s += temp % 2 + '0';
        }
        if (add)
        {
            s += '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
