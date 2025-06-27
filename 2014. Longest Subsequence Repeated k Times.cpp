#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
private:
    bool valid(const string& s,const string& p,int k)
    {
        int i=0,cnt=0;
        for(char c:s)
        {
            if(c==p[i])
            {
                i++;
                if(i==p.size())
                {
                    i=0;
                    cnt++;
                    if(cnt==k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
public:
    string longestSubsequenceRepeatedK(const string& s, int k)
    {
        int freq[26]={0};
        for(char c:s)
        {
            freq[c-'a']++;
        }
        int mask=0;
        queue<string> q;
        for(int i=25;i>=0;i--)
        {
            if(freq[i]>=k)
            {
                mask|=1<<i;
                q.push(string(1,i+'a'));
            }
        }
        string ans="";
        while(!q.empty())
        {
            string cur=q.front();
            q.pop();
            if(cur.size()>ans.size())
            {
                ans=cur;
            }
            for(int i=25;i>=0;i--)
            {
                char c='a'+i;
                if(valid(s,cur+c,k))
                {
                    q.push(cur+c);
                }
            }
        }
        return ans;
    }
};
