#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int strongPasswordChecker(const string& password)
    {
        int miss = 3;
        bool f1 = true, f2 = true, f3 = true;
        for (char c:password)
        {
            if (f1 && c >= 'a' && c <= 'z')
            {
                f1 = false;
                miss--;
            }
            if (f2 && c >= 'A' && c <= 'Z')
            {
                f2 = false;
                miss--;
            }
            if (f3 && c >= '0' && c <= '9')
            {
                f3 = false;
                miss--;
            }
        }
        int change = 0;
        int one = 0,two = 0;
        int p = 2;
        int n = (int)password.size();
        while (p < n)
        {
            if (password[p] == password[p - 1] && password[p] == password[p - 2])
            {
                int len = 2;
                while (p < n && password[p] == password[p - 1])
                {
                    len++;
                    p++;
                }
                change += len / 3;
                if (len % 3 == 0)
                {
                    one++;
                }
                else if (len % 3 == 1)
                {
                    two++;
                }
            }
            else
            {
                p++;
            }
        }
        if (n < 6)
        {
            return max(miss, 6 - n);
        }
        else if (n <= 20)
        {
            return max(miss, change);
        }
        else
        {
            int del = n - 20;
            change -= min(del, one);
            change -= min(max(del - one, 0), two * 2) / 2;
            change -= max(del - one - 2 * two, 0) / 3;
            return del + max(miss, change);
        }
    }
};
