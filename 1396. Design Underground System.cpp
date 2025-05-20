#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class UndergroundSystem
{
public:
    unordered_map<int,pair<string,int>> time;
    unordered_map<string, unordered_map<string, pair<long long,int>>> list;
    
    UndergroundSystem()
    {
       
    }
    
    void checkIn(int id, const string& stationName, int t)
    {
        time[id]={stationName,t};
    }
    
    void checkOut(int id, const string& s2, int t2)
    {
        auto [s1,t1]=time[id];
        time.erase(id);
        list[s1][s2].first+=t2-t1;
        list[s1][s2].second++;
    }
    
    double getAverageTime(const string& s1, const string& s2)
    {
        return list[s1][s2].first/1.0/list[s1][s2].second;
    }
};
