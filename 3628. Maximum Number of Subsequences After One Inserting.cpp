#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long numOfSubsequences(const string& s)
    {
        int n = (int)s.size();
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'T')
            {
                t++;
            }
        }
        long long temp1 = 0, temp2 = 0, temp3 = 0;
        long long k = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            k = max(k, l * t);
            switch (s[i])
            {
                case 'L':
                    l++;
                    break;
                case 'C':
                    temp1 += (l + 1) * t;
                    temp2 += l * t;
                    temp3 += l * (t + 1);
                    break;
                case 'T':
                    t--;
                    break;
            }
        }
        return max(temp2 + k, max(temp1, temp3));
    }
};
