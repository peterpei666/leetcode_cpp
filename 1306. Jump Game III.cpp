#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int>& arr, int start)
    {
        int n=(int)arr.size();
        bitset<50000> list;
        list.set(start);
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            int l=temp-arr[temp];
            int r=temp+arr[temp];
            if(l>=0&&l<n&&list.test(l)==false)
            {
                list.set(l);
                q.push(l);
            }
            if(r>=0&&r<n&&list.test(r)==false)
            {
                list.set(r);
                q.push(r);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0&&list.test(i))
            {
                return true;
            }
        }
        return false;
    }
};
