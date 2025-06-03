#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> getStrongest(vector<int>& arr, int k)
    {
        sort(arr.begin(),arr.end());
        int center=arr[(arr.size()-1)/2];
        sort(arr.begin(),arr.end(),[&](const int a,const int b){ return abs(a-center)==abs(b-center)?a>b:abs(a-center)>abs(b-center); });
        vector<int> ret(k);
        for(int i=0;i<k;i++)
        {
            ret[i]=arr[i];
        }
        return ret;
    }
};
