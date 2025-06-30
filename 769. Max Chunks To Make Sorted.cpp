#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int stk[10];
        int k=0;
        for(int i:arr)
        {
            if(k&&stk[k-1]>i)
            {
                int temp=stk[k-1];
                while(k&&stk[k-1]>i)
                {
                    k--;
                }
                stk[k]=temp;
                k++;
            }
            else
            {
                stk[k]=i;
                k++;
            }
        }
        return (int)k;
    }
};
