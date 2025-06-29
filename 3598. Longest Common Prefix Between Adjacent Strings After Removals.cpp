#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    inline int lcp(const string& a,const string& b)
    {
        int i=0,n=(int)min(a.size(),b.size());
        while(i<n&&a[i]==b[i]) i++;
        return i;
    }
    
public:
    vector<int> longestCommonPrefix(vector<string>& words)
    {
        int n=(int)words.size();
        if(n==1)
        {
            return {0};
        }
        int list[n-1];
        for(int i=0;i<n-1;i++)
        {
            list[i]=lcp(words[i],words[i+1]);
        }
        int prefix[n-1];
        prefix[0]=list[0];
        for(int i=1;i<n-1;i++)
        {
            prefix[i]=max(prefix[i-1],list[i]);
        }
        int suffix[n-1];
        suffix[n-2]=list[n-2];
        for(int i=n-3;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],list[i]);
        }
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            int temp=0;
            if(i!=0&&i!=n-1)
            {
                temp=max(temp,lcp(words[i-1],words[i+1]));
            }
            if(i-2>=0)
            {
                temp=max(temp,prefix[i-2]);
            }
            if(i+1<n-1)
            {
                temp=max(temp,suffix[i+1]);
            }
            ret[i]=temp;
        }
        return ret;
    }
};
