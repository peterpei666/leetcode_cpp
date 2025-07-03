#include <iostream>
#include <algorithm>
using namespace std;

class MyCalendar
{
private:
    vector<pair<int,int>> list;
    
public:
    MyCalendar()
    {
        list.clear();
    }
    
    bool book(int startTime, int endTime)
    {
        int i,n=(int)list.size();
        for(i=0;i<n;i++)
        {
            if(!(endTime<=list[i].first||startTime>=list[i].second))
            {
                return false;
            }
        }
        list.push_back({startTime,endTime});
        return true;
    }
};
