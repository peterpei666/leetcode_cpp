#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bestClosingTime(const string& customers)
    {
        int n = (int)customers.size();
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
            {
                temp++;
            }
        }
        int ans = temp;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
            {
                temp--;
            }
            else
            {
                temp++;
            }
            if (ans > temp)
            {
                ans = temp;
                t = i + 1;
            }
        }
        return t;
    }
};
