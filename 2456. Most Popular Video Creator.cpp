#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    struct person
    {
        string video;
        int m;
        long long total;
    };
    
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views)
    {
        int n=(int)creators.size();
        unordered_map<string,person> list;
        for(int i=0;i<n;i++)
        {
            auto& [video,m,total]=list[creators[i]];
            total+=views[i];
            if(views[i]>m||video.empty())
            {
                m=views[i];
                video=ids[i];
            }
            else if(views[i]==m&&ids[i]<video)
            {
                m=views[i];
                video=ids[i];
            }
        }
        long long maxi=0;
        for(auto& [name,p]:list)
        {
            maxi=max(maxi,p.total);
        }
        vector<vector<string>> ret;
        for(auto& [name,p]:list)
        {
            if(p.total==maxi)
            {
                ret.push_back({name,p.video});
            }
        }
        return ret;
    }
};
