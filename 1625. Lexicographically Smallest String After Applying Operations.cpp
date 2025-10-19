#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class Solution
{
private:
    string add(string s, int a)
    {
        int n = (int)s.size();
        for (int i = 1; i < n; i += 2)
        {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }
        return s;
    }
    
    string rotate(string s, int b)
    {
        int n = (int)s.size();
        std::rotate(s.begin(), s.begin() + (n - b), s.end());
        return s;
    }
    
public:
    string findLexSmallestString(string s, int a, int b)
    {
        set<string> mp;
        mp.insert(s);
        stack<string> stk;
        stk.push(s);
        while (!stk.empty())
        {
            string temp = stk.top();
            stk.pop();
            string t = add(temp, a);
            if (!mp.count(t))
            {
                mp.insert(t);
                stk.push(t);
            }
            t = rotate(temp, b);
            if (!mp.count(t))
            {
                mp.insert(t);
                stk.push(t);
            }
        }
        return *mp.begin();
    }
};
