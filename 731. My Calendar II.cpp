#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class MyCalendarTwo
{
private:
    map<int, int> mp;
    
public:
    MyCalendarTwo() {}
    
    bool book(int startTime, int endTime)
    {
        mp[startTime]++;
        mp[endTime]--;
        int cnt = 0;
        bool valid = true;
        for (auto [_, n] : mp)
        {
            cnt += n;
            if (cnt > 2)
            {
                valid = false;
                break;
            }
        }
        if (valid == false)
        {
            mp[startTime]--;
            mp[endTime]++;
        }
        return valid;
    }
};
