#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool compare(const pair<int,int>& a,const pair<int,int>& b)
    {
        return a.second>b.second;
    }
    
    int maxProduct(vector<string>& words)
    {
        int n=(int)words.size();
        vector<pair<int,int>> list;
        for(int i=0;i<n;i++)
        {
            int mask=0;
            for(char c:words[i])
            {
                mask|=1<<(c-'a');
            }
            list.emplace_back(mask,words[i].size());
        }
        sort(list.begin(),list.end(),compare);
        int max=0;
        for(int i=0;i<n;i++)
        {
            if(list[i].second*list[i].second<=max)
            {
                break;
            }
            for(int j=i+1;j<n;j++)
            {
                int temp=list[i].second*list[j].second;
                if(temp<=max)
                {
                    break;
                }
                if((list[i].first&list[j].first)==0)
                {
                    max=temp;
                    break;
                }
            }
        }
        return max;
    }
};
