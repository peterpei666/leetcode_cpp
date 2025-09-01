#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getMaxRepetitions(const string& s1, int n1, const string& s2, int n2)
    {
        if (n1 == 0)
        {
            return 0;
        }
        int l1 = (int)s1.size();
        int l2 = (int)s2.size();
        int indexr[l2 + 1];
        int countr[l2 + 1];
        memset(indexr, 0, sizeof(indexr));
        memset(countr, 0, sizeof(countr));
        int idx = 0;
        int cnt = 0;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                if (s1[j] == s2[idx])
                {
                    idx++;
                }
                if (idx == l2)
                {
                    cnt++;
                    idx = 0;
                }
            }
            countr[i] = cnt;
            indexr[i] = idx;
            for (int k = 0; k < i; k++)
            {
                if (indexr[k] == idx)
                {
                    int prev = countr[k];
                    int patt = (countr[i] - countr[k]) * ((n1 - k - 1) / (i - k));
                    int rem = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];
                    return (prev + patt + rem) / n2;
                }
            }
        }
        return countr[n1 -1] / n2;
    }
};
