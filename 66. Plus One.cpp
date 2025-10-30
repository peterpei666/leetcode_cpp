#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int n = (int)digits.size() - 1;
        bool add = true;
        while (n >= 0 && add)
        {
            digits[n]++;
            add = digits[n] >= 10;
            digits[n] %= 10;
            n--;
        }
        if (add)
        {
            vector<int> temp(1, 1);
            temp.insert(temp.end(), digits.begin(), digits.end());
            return temp;
        }
        return digits;
    }
};
