#include <iostream>
#include <algorithm>
using namespace std;

class CustomStack
{
public:
    vector<int> stack;
    int sz;
    
    CustomStack(int maxSize)
    {
        sz=maxSize;
    }
    
    void push(int x)
    {
        if(stack.size()<sz)
        {
            stack.push_back(x);
        }
    }
    
    int pop()
    {
        if(stack.empty())
        {
            return -1;
        }
        int ret=stack.back();
        stack.pop_back();
        return ret;
    }
    
    void increment(int k, int val)
    {
        for(int i=0;i<k&&i<stack.size();i++)
        {
            stack[i]+=val;
        }
    }
};
