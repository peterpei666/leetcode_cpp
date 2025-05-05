#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int parent[26];
    
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        else
        {
            parent[x]=find(parent[x]);
            return parent[x];
        }
    }
    
    void unite(int a,int b)
    {
        int root1=find(a);
        int root2=find(b);
        if(root1!=root2)
        {
            if(root1<root2)
            {
                parent[root2]=root1;
            }
            else
            {
                parent[root1]=root2;
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        int n=(int)s1.size();
        for(int i=0;i<n;i++)
        {
            unite(s1[i]-'a',s2[i]-'a');
        }
        n=(int)baseStr.size();
        for(int i=0;i<n;i++)
        {
            baseStr[i]=find(baseStr[i]-'a')+'a';
        }
        return baseStr;
    }
};
