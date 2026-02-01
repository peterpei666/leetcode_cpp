#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_set>
using namespace std;

class RideSharingSystem
{
private:
    deque<int> rider;
    deque<int> driver;
    unordered_set<int> valid;
    
public:
    RideSharingSystem() {}
    
    void addRider(int riderId)
    {
        rider.push_back(riderId);
        valid.insert(riderId);
    }
    
    void addDriver(int driverId)
    {
        driver.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider()
    {
        while (!rider.empty() && !valid.count(rider.front()))
        {
            rider.pop_front();
        }
        if (!rider.empty() && !driver.empty())
        {
            vector<int> ans = {driver.front(), rider.front()};
            driver.pop_front();
            rider.pop_front();
            return ans;
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId)
    {
        if (valid.count(riderId))
        {
            valid.erase(riderId);
        }
    }
};
