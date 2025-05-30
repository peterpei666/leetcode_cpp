#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        int n=(int)edges.size();
        int list1[n];
        int list2[n];
        memset(list1,-1,sizeof(list1));
        memset(list2,-1,sizeof(list2));
        list1[node1]=0;
        list2[node2]=0;
        int cnt;
        cnt=0;
        while(edges[node1]!=-1)
        {
            node1=edges[node1];
            cnt++;
            if(list1[node1]!=-1)
            {
                break;
            }
            list1[node1]=cnt;
        }
        cnt=0;
        while(edges[node2]!=-1)
        {
            node2=edges[node2];
            cnt++;
            if(list2[node2]!=-1)
            {
                break;
            }
            list2[node2]=cnt;
        }
        int ans=INT_MAX,p=-1;
        for(int i=0;i<n;i++)
        {
            if(list1[i]==-1||list2[i]==-1)
            {
                continue;
            }
            if(ans>max(list1[i],list2[i]))
            {
                ans=max(list1[i],list2[i]);
                p=i;
            }
        }
        return p;
    }
};
