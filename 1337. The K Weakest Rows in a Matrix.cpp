#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<pair<int,int>> list(mat.size());
        int l=0;
        for(auto& line:mat)
        {
            int count=0;
            for(int i:line)
            {
                if(i)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            list[l]={count,l};
            l++;
        }
        sort(list.begin(),list.end());
        vector<int> ret(k);
        for(int i=0;i<k;i++)
        {
            ret[i]=list[i].second;
        }
        return ret;
    }
};
