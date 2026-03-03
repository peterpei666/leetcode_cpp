#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <deque>
using namespace std;

class AuthenticationManager
{
private:
    int time;
    int live;
    unordered_map<string, int> mp;
    deque<pair<string, int>> q;
    
    void clear(int cur)
    {
        while (!q.empty() && q.front().second <= cur)
        {
            if (mp[q.front().first] == q.front().second)
            {
                live--;
                mp.erase(q.front().first);
            }
            q.pop_front();
        }
    }
    
public:
    AuthenticationManager(int timeToLive)
    {
        live = 0;
        time = timeToLive;
    }
    
    void generate(const string& tokenId, int currentTime)
    {
        clear(currentTime);
        live++;
        mp[tokenId] = currentTime + time;
        q.push_back(make_pair(tokenId, mp[tokenId]));
    }
    
    void renew(const string& tokenId, int currentTime)
    {
        clear(currentTime);
        if (mp.count(tokenId))
        {
            mp[tokenId] = currentTime + time;
            q.push_back(make_pair(tokenId, mp[tokenId]));
        }
    }
    
    int countUnexpiredTokens(int currentTime)
    {
        clear(currentTime);
        return live;
    }
};
