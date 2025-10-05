#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeSubstring(const string& s, int k)
    {
        stack<pair<char,int>> stk;
        for (char c : s)
        {
            if (stk.empty() || stk.top().first != c)
            {
                stk.push({c, 1});
            }
            else
            {
                stk.top().second++;
            }
            while (stk.size() >= 2)
            {
                auto t1 = stk.top();
                stk.pop();
                auto t2 = stk.top();
                stk.pop();
                if (t1.first == ')' && t2.first == '(' && t1.second >= k && t2.second >= k)
                {
                    t1.second -= k;
                    t2.second -= k;
                    if (t2.second > 0)
                    {
                        stk.push(t2);
                    }
                    if (t1.second > 0)
                    {
                        stk.push(t1);
                    }
                }
                else
                {
                    stk.push(t2);
                    stk.push(t1);
                    break;
                }
            }
        }
        string ans;
        vector<pair<char, int>> temp;
        while (!stk.empty())
        {
            temp.push_back(stk.top());
            stk.pop();
        }
        reverse(temp.begin(), temp.end());
        for (auto [c, cnt] : temp)
        {
            ans += string(cnt, c);
        }
        return ans;
    }
};
