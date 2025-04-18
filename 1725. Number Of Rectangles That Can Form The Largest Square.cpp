#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles)
    {
        int maxlen=0,count=0,temp,i,sz=(int)rectangles.size();
        for(i=0;i<sz;i++)
        {
            temp=min(rectangles[i][0],rectangles[i][1]);
            if(temp>maxlen)
            {
                maxlen=temp;
                count=1;
            }
            else if(temp==maxlen)
            {
                count++;
            }
        }
        return count++;
    }
};
