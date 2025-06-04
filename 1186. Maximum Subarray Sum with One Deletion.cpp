#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<int>& arr)
    {
        int n=(int)arr.size();
        int cur,temp;
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=arr[0];
        cur=arr[0];
        temp=arr[0];
        for(int i=1;i<n;i++)
        {
            cur=max(arr[i],cur+arr[i]);
            temp=max(temp,cur);
            prefix[i]=cur;
        }
        suffix[n-1]=arr[n-1];
        cur=arr[n-1];
        temp=max(temp,arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            cur=max(arr[i],cur+arr[i]);
            temp=max(temp,cur);
            suffix[i]=cur;
        }
        int ans=temp;
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,prefix[i-1]+suffix[i+1]);
        }
        return ans;
    }
};
