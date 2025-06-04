#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(const string& s, int k)
    {
        int n=(int)s.size();
        if(n-k+1<(1<<k))
        {
            return false;
        }
        bitset<1050000> list;
        int temp=0;
        for(int i=0;i<k;i++)
        {
            temp<<=1;
            temp+=s[i]-'0';
        }
        list.set(temp);
        for(int i=k;i<n;i++)
        {
            temp<<=1;
            temp+=s[i]-'0';
            temp&=(1<<k)-1;
            list.set(temp);
        }
        return list.count()==1<<k;
    }
};
