#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
private:
    void init(vector<long long>& mp)
    {
        vector<char> half;
        string mid;
        for (int mask = 1; mask < (1 << 9); mask++)
        {
            int sum = 0;
            int odd = 0;
            for (int d = 1; d <= 9; d++)
            {
                if (mask & (1 << (d - 1)))
                {
                    sum += d;
                    if (d & 1)
                    {
                        odd++;
                    }
                }
            }
            if (sum > 18 || odd > 1)
            {
                continue;
            }
            half.clear();
            mid.clear();
            for (int d = 1; d <= 9; d++)
            {
                if (mask & (1 << (d - 1)))
                {
                    int cnt = d;
                    if (cnt & 1)
                    {
                        mid = string(1, '0' + d);
                    }
                    int h = cnt / 2;
                    while (h)
                    {
                        h--;
                        half.push_back('0' + d);
                    }
                }
            }
            sort(half.begin(), half.end());
            do {
                string left(half.begin(), half.end());
                string right = left;
                reverse(right.begin(), right.end());
                string s = left + mid + right;
                if (!s.empty())
                {
                    mp.push_back(stoll(s));
                }
            } while (next_permutation(half.begin(), half.end()));
            sort(mp.begin(), mp.end());
            mp.erase(unique(mp.begin(), mp.end()),mp.end());
        }
    }
    
public:
    long long specialPalindrome(long long n)
    {
        static vector<long long> mp;
        if (mp.empty())
        {
            init(mp);
        }
        return *upper_bound(mp.begin(), mp.end(), n);
    }
};
