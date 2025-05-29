#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValid(const string& s)
    {
        vector<char> stack;
        for(char c:s)
        {
            if(c!='c')
            {
                stack.push_back(c);
            }
            else
            {
                if(stack.size()<2)
                {
                    return false;
                }
                int i=(int)stack.size();
                if(stack[i-1]=='b'&&stack[i-2]=='a')
                {
                    stack.pop_back();
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(c);
                }
            }
        }
        return stack.size()==0;
    }
};
