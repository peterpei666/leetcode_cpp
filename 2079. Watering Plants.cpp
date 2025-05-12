#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int wateringPlants(vector<int>& plants, int capacity)
    {
        int ret=0,t=capacity;
        int n=(int)plants.size();
        for(int i=0;i<n;i++)
        {
            ret++;
            if(t<plants[i])
            {
                t=capacity;
                ret+=2*i;
            }
            t-=plants[i];
        }
        return ret;
    }
};
