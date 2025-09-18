#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class TaskManager
{
private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, pair<int, int>> mp;
    
public:
    TaskManager(vector<vector<int>>& tasks)
    {
        for (auto& task : tasks)
        {
            pq.push({task[2], task[1]});
            mp[task[1]] = {task[0], task[2]};
        }
    }
    
    void add(int userId, int taskId, int priority)
    {
        pq.push({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority)
    {
        pq.push({newPriority, taskId});
        mp[taskId].second = newPriority;
    }
    
    void rmv(int taskId)
    {
        mp.erase(taskId);
    }
    
    int execTop()
    {
        while (!pq.empty())
        {
            auto [p, t] = pq.top();
            if (!mp.count(t) || mp[t].second != p)
            {
                pq.pop();
            }
            else
            {
                break;
            }
        }
        if (!pq.empty())
        {
            auto [_, t] = pq.top();
            pq.pop();
            int ans = mp[t].first;
            mp.erase(t);
            return ans;
        }
        else
        {
            return -1;
        }
    }
};
