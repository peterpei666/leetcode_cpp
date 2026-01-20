#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class AuctionSystem
{
private:
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, priority_queue<pair<int, int>>> q;
    
public:
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount)
    {
        mp[itemId][userId] = bidAmount;
        q[itemId].push(make_pair(bidAmount, userId));
    }
    
    void updateBid(int userId, int itemId, int newAmount)
    {
        mp[itemId][userId] = newAmount;
        q[itemId].push(make_pair(newAmount, userId));
    }
    
    void removeBid(int userId, int itemId)
    {
        mp[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId)
    {
        if (!q.count(itemId))
        {
            return -1;
        }
        while (!q[itemId].empty() && (!mp[itemId].count(q[itemId].top().second) || mp[itemId][q[itemId].top().second] != q[itemId].top().first))
        {
            q[itemId].pop();
        }
        if(q[itemId].empty())
        {
            return -1;
        }
        return q[itemId].top().second;
    }
};
