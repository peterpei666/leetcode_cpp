#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class MyCalendarThree
{
private:
    map<int, int> mp;
    
public:
    MyCalendarThree() {}
    
    int book(int startTime, int endTime)
    {
        mp[startTime]++;
        mp[endTime]--;
        int cnt = 0;
        int ans = 0;
        for (auto [_, n] : mp)
        {
            cnt += n;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
