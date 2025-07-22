#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int>& colors)
    {
        int cnt=0;
        int n=(int)colors.size();
        for(int i=0;i<n;i++)
        {
            if(colors[(i-2+n)%n]!=colors[(i-1+n)%n]&&colors[i]!=colors[(i-1+n)%n])
            {
                cnt++;
            }
        }
        return cnt;
    }
};
