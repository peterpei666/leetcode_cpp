#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool check(int d,vector<vector<int>>& rectangles)
    {
        sort(rectangles.begin(),rectangles.end(),[&](const vector<int>& a,const vector<int>& b) { return a[d]<b[d]; });
        int n=(int)rectangles.size();
        int cnt=0;
        int cur=rectangles[0][d+2];
        for(int i=1;i<n;i++)
        {
            if(cur<=rectangles[i][d])
            {
                cnt++;
                if(cnt>=2)
                {
                    return true;
                }
            }
            cur=max(cur,rectangles[i][d+2]);
        }
        return false;
    }
    
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles)
    {
        return check(0,rectangles)||check(1,rectangles);
    }
};
