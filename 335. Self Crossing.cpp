#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isSelfCrossing(vector<int>& distance)
    {
        if(distance.size()<4)
        {
            return false;
        }
        distance.insert(distance.begin(),0);
        int n=(int)distance.size();
        for(int i=3;i<n;i++)
        {
            if(distance[i-2]<=distance[i]&&distance[i-3]>=distance[i-1])
            {
                return true;
            }
            if(i>=5)
            {
                if(distance[i-2]>=distance[i-4]&&distance[i-2]<=distance[i-4]+distance[i]&&distance[i-3]>=distance[i-1]&&distance[i-3]<=distance[i-1]+distance[i-5])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
