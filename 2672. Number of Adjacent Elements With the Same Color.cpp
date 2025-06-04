#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries)
    {
        vector<int> list(n+2,0);
        int cnt=0;
        int m=(int)queries.size();
        vector<int> ret(m);
        for(int i=0;i<m;i++)
        {
            int p=queries[i][0]+1;
            if(list[p])
            {
                if(list[p-1]==list[p])
                {
                    cnt--;
                }
                if(list[p+1]==list[p])
                {
                    cnt--;
                }
            }
            list[p]=queries[i][1];
            if(list[p-1]==list[p])
            {
                cnt++;
            }
            if(list[p+1]==list[p])
            {
                cnt++;
            }
            ret[i]=cnt;
        }
        return ret;
    }
};
