#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> mstk;
    
public:
    MinStack() {}
    
    void push(int val)
    {
        stk.push(val);
        if (mstk.empty() || val <= mstk.top())
        {
            mstk.push(val);
        }
    }
    
    void pop()
    {
        int val = stk.top();
        stk.pop();
        if (mstk.top() == val)
        {
            mstk.pop();
        }
    }
    
    int top()
    {
        return stk.top();
    }
    
    int getMin()
    {
        return mstk.top();
    }
};
