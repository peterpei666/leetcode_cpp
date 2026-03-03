#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class BrowserHistory
{
private:
    deque<string> q1;
    deque<string> q2;
    
public:
    BrowserHistory(const string& homepage)
    {
        q1.push_back(homepage);
    }
    
    void visit(const string& url)
    {
        q1.push_back(url);
        if (!q2.empty())
        {
            q2 = deque<string>();
        }
    }
    
    string back(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (q1.size() == 1)
            {
                break;
            }
            string temp = q1.back();
            q1.pop_back();
            q2.push_front(temp);
        }
        return q1.back();
    }
    
    string forward(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (q2.empty())
            {
                break;
            }
            string temp = q2.front();
            q2.pop_front();
            q1.push_back(temp);
        }
        return q1.back();
    }
};
