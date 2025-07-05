#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int>& arr)
    {
        int freq[501]={0};
        for(int i:arr)
        {
            freq[i]++;
        }
        for(int i=500;i>=1;i--)
        {
            if(freq[i]==i)
            {
                return i;
            }
        }
        return -1;
    }
};
