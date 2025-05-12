#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int i=0,j=(int)plants.size()-1;
        int ret=0;
        int c1=capacityA,c2=capacityB;
        while(i<j)
        {
            ret+=(c1<plants[i])+(c2<plants[j]);
            c1=c1<plants[i]?capacityA:c1;
            c2=c2<plants[j]?capacityB:c2;
            c1-=plants[i];
            c2-=plants[j];
            i++;
            j--;
        }
        ret+=(i==j&&max(c1,c2)<plants[i]);
        return ret;
    }
};
