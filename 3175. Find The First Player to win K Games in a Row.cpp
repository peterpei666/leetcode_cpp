#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findWinningPlayer(vector<int>& skills, int k)
    {
        int n=(int)skills.size();
        int j=0;
        for(int i=1,cur=0;i<n;i++)
        {
            if(skills[i]>skills[j])
            {
                j=i;
                cur=0;
            }
            cur++;
            if(cur==k)
            {
                break;
            }
        }
        return j;
    }
};
