#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy)
    {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0]>currentEnergy)
        {
            return 0;
        }
        int n=(int)enemyEnergies.size()-1;
        long long ans=0;
        while(n>=0)
        {
            if(enemyEnergies[0]<=currentEnergy)
            {
                ans+=currentEnergy/enemyEnergies[0];
                currentEnergy%=enemyEnergies[0];
            }
            else
            {
                currentEnergy+=enemyEnergies[n];
                n--;
            }
        }
        return ans;
    }
};
