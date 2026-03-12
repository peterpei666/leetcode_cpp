#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> stk;
        for (const string& s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                int t2 = stk.top();
                stk.pop();
                int t1 = stk.top();
                stk.pop();
                if (s == "+")
                {
                    stk.push(t1 + t2);
                }
                else if (s == "-")
                {
                    stk.push(t1 - t2);
                }
                else if (s == "*")
                {
                    stk.push(t1 * t2);
                }
                else
                {
                    stk.push(t1 / t2);
                }
            }
            else
            {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
