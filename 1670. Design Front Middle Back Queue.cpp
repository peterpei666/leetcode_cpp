#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class FrontMiddleBackQueue
{
private:
    deque<int> q1;
    deque<int> q2;
    
    void rebalance()
    {
        while (q1.size() > q2.size())
        {
            int temp = q1.back();
            q1.pop_back();
            q2.push_front(temp);
        }
        while (q2.size() > q1.size() + 1)
        {
            int temp = q2.front();
            q2.pop_front();
            q1.push_back(temp);
        }
    }
    
public:
    void pushFront(int val)
    {
        q1.push_front(val);
        rebalance();
    }
    
    void pushMiddle(int val)
    {
        q1.push_back(val);
        rebalance();
    }
    
    void pushBack(int val)
    {
        q2.push_back(val);
        rebalance();
    }
    
    int popFront()
    {
        if (q1.empty() && q2.empty())
        {
            return -1;
        }
        int ans;
        if (q1.empty())
        {
            ans = q2.front();
            q2.pop_front();
        }
        else
        {
            ans = q1.front();
            q1.pop_front();
        }
        rebalance();
        return ans;
    }
    
    int popMiddle()
    {
        if (q1.empty() && q2.empty())
        {
            return -1;
        }
        int ans;
        if (q2.size() > q1.size())
        {
            ans = q2.front();
            q2.pop_front();
        }
        else
        {
            ans = q1.back();
            q1.pop_back();
        }
        rebalance();
        return ans;
    }
    
    int popBack()
    {
        if (q2.empty())
        {
            return -1;
        }
        int ans = q2.back();
        q2.pop_back();
        rebalance();
        return ans;
    }
};
