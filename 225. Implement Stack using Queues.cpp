#include <iostream>
#include <algorithm>
using namespace std;

class MyStack
{
private:
    int sz;
    int stk[100];
    
public:
    MyStack()
    {
        sz = 0;
    }
    
    void push(int x)
    {
        stk[sz] = x;
        sz++;
    }
    
    int pop()
    {
        sz--;
        return stk[sz];
    }
    
    int top()
    {
        return stk[sz - 1];
    }
    
    bool empty()
    {
        return sz == 0;
    }
};
