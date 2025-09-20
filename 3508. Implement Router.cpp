#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

struct PacketHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto [a, b, c] = t;
        size_t h1 = hash<int>()(a);
        size_t h2 = hash<int>()(b);
        size_t h3 = hash<int>()(c);
        return ((h1 ^ (h2 << 1)) >> 1) ^ (h3 << 1);
    }
};

class Router
{
private:
    int limit;
    unordered_set<tuple<int, int, int>, PacketHash> exist;
    deque<tuple<int,int,int>> dq;
    unordered_map<int, pair<vector<int>, int>> mp;
    
    
public:
    Router(int memoryLimit)
    {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp)
    {
        if (exist.count({source, destination, timestamp}))
        {
            return false;
        }
        if (dq.size() == limit)
        {
            forwardPacket();
        }
        exist.insert({source, destination, timestamp});
        dq.push_back({source, destination, timestamp});
        mp[destination].first.push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket()
    {
        if (dq.empty())
        {
            return {};
        }
        auto [source, destination, timestamp] = dq.front();
        dq.pop_front();
        exist.erase({source, destination, timestamp});
        mp[destination].second++;
        return {source, destination, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime)
    {
        auto& [time, k] = mp[destination];
        return (int)(upper_bound(time.begin() + k, time.end(), endTime) - lower_bound(time.begin() + k, time.end(), startTime));
    }
};
