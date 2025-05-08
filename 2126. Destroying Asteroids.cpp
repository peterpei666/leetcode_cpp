#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        sort(asteroids.begin(),asteroids.end());
        int len=(int)asteroids.size();
        for(int m:asteroids)
        {
            if(mass>=asteroids[len-1])
            {
                return true;
            }
            if(mass>=m)
            {
                mass+=m;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
