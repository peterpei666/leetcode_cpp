#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n=(int)ratings.size();
        int list[n];
        fill(&list[0],&list[0]+n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                list[i]=list[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                list[i]=max(list[i],list[i+1]+1);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=list[i];
        }
        return cnt;
    }
};
