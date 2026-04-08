#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class EventManager
{
private:
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    
public:
    EventManager(vector<vector<int>>& events)
    {
        for (auto& e : events)
        {
            mp[e[0]] = e[1];
            pq.push(make_pair(e[1], -e[0]));
        }
    }
    
    void updatePriority(int eventId, int newPriority)
    {
        if (mp.count(eventId))
        {
            mp[eventId] = newPriority;
            pq.push(make_pair(newPriority, -eventId));
        }
    }
    
    int pollHighest()
    {
        while (!pq.empty())
        {
            auto [p, id] = pq.top();
            pq.pop();
            if (mp.count(-id) && mp[-id] == p)
            {
                mp.erase(-id);
                return -id;
            }
        }
        return -1;
    }
};
