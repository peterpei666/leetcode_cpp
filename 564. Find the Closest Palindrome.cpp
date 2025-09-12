#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    long long construct(long long h, bool even)
    {
        long long res = h;
        if (!even)
        {
            h /= 10;
        }
        while (h > 0)
        {
            res = res * 10 + h % 10;
            h /= 10;
        }
        return res;
    }
    
public:
    string nearestPalindromic(const string& n)
    {
        int len = (int)n.size();
        long long fh = stoll(n.substr(0, (len + 1) / 2));
        vector<long long> pos;
        pos.push_back(construct(fh, len % 2 == 0));
        if(fh > 0) pos.push_back(construct(fh - 1, len % 2 == 0));
        pos.push_back(construct(fh + 1, len % 2 == 0));
        pos.push_back((long long)pow(10, len - 1) - 1);
        pos.push_back((long long)pow(10, len) + 1);
        long long dif = LONG_MAX;
        long long ans = 0;
        long long n_val = stoll(n);
        for (auto p : pos)
        {
            if (p == n_val)
            {
                continue;
            }
            if (abs(p - n_val) < dif)
            {
                dif = abs(p - n_val);
                ans = p;
            }
            else if (abs(p - n_val) == dif)
            {
                ans = min(ans, p);
            }
        }
        return to_string(ans);
    }
};
