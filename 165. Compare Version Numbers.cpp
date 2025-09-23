#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int compareVersion(const string& version1, const string& version2)
    {
        int m = (int)version1.size();
        int n = (int)version2.size();
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            int temp1 = 0;
            while (i < m && version1[i] != '.')
            {
                temp1 = temp1 * 10 - '0' + version1[i];
                i++;
            }
            i++;
            int temp2 = 0;
            while (j < n && version2[j] != '.')
            {
                temp2 = temp2 * 10 - '0' + version2[j];
                j++;
            }
            j++;
            if (temp1 > temp2)
            {
                return 1;
            }
            if (temp1 < temp2)
            {
                return -1;
            }
        }
        return 0;
    }
};
