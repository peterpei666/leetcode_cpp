#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2)
    {
        int m=0,n=0;
        for(int i:arr1)
        {
            m^=i;
        }
        for(int i:arr2)
        {
            n^=i;
        }
        return m&n;
    }
};
