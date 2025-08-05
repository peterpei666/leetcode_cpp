#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        int n=(int)fruits.size();
        bitset<100> used;
        for(int f:fruits)
        {
            for(int i=0;i<n;i++)
            {
                if(used.test(i)==false&&baskets[i]>=f)
                {
                    used.set(i);
                    break;
                }
            }
        }
        return n-(int)used.count();
    }
};
