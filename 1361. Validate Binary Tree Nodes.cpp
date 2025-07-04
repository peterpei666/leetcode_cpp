#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int find(int root[],int x)
    {
        if(root[x]==x)
        {
            return x;
        }
        root[x]=find(root,root[x]);
        return root[x];
    }
    
    void join(int root[],int a,int b)
    {
        int r1=find(root,a);
        int r2=find(root,b);
        if(r1<r2)
        {
            root[r2]=r1;
        }
        else
        {
            root[r1]=r2;
        }
    }
    
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        int parent[n];
        int root[n];
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<n;i++)
        {
            root[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                if(parent[leftChild[i]]!=-1)
                {
                    return false;
                }
                parent[leftChild[i]]=i;
                join(root,i,leftChild[i]);
            }
            if(rightChild[i]!=-1)
            {
                if(parent[rightChild[i]]!=-1)
                {
                    return false;
                }
                parent[rightChild[i]]=i;
                join(root,i,rightChild[i]);
            }
        }
        bool r=false;
        int t=find(root,0);
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                if(r)
                {
                    return false;
                }
                r=true;
            }
            if(find(root,i)!=t)
            {
                return false;
            }
        }
        return r;
    }
};
