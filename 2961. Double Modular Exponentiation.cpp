#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int mod2[4]={6,2,4,8};
    int mod3[4]={1,3,9,7};
    int mod7[4]={1,7,9,3};
    int mod8[4]={6,8,4,2};
    int mod4[2]={6,4};
    int mod9[2]={1,9};
    
    int mod(int base,int exp)
    {
        switch(base)
        {
            case 2:
                return mod2[exp%4];
            case 3:
                return mod3[exp%4];
            case 4:
                return mod4[exp%2];
            case 7:
                return mod7[exp%4];
            case 8:
                return mod8[exp%4];
            case 9:
                return mod9[exp%2];
            default:
                return base;
        }
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target)
    {
        vector<int> ret;
        for(int i=0;i<variables.size();i++)
        {
            if(variables[i][3]<=target)
            {
                continue;
            }
            short temp=mod(variables[i][0]%10,variables[i][1]);
            short x=1,t=variables[i][2];
            for(short j=0;j<t;j++)
            {
                x=temp*x%variables[i][3];
            }
            if(x==target)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
