#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    string countOfAtoms(const string& formula)
    {
        stack<map<string, int>> stk;
        stk.push(map<string, int>());
        int n = (int)formula.size();
        string cur = "";
        string num = "";
        for (int i = 0; i < n; i++)
        {
            if (formula[i] == '(')
            {
                if (!cur.empty())
                {
                    int cnt = num.empty() ? 1 : stoi(num);
                    stk.top()[cur] += cnt;
                    cur = "";
                    num = "";
                }
                stk.push(map<string, int>());
            }
            else if (formula[i] >= 'A' && formula[i] <= 'Z')
            {
                if (!cur.empty())
                {
                    int cnt = num.empty() ? 1 : stoi(num);
                    stk.top()[cur] += cnt;
                    cur = "";
                    num = "";
                }
                cur = formula[i];
            }
            else if (formula[i] >= 'a' && formula[i] <= 'z')
            {
                cur += formula[i];
            }
            else if (formula[i] == ')')
            {
                if (!cur.empty())
                {
                    int cnt = num.empty() ? 1 : stoi(num);
                    stk.top()[cur] += cnt;
                    cur = "";
                    num = "";
                }
                map<string, int> top = stk.top();
                stk.pop();
                string mulStr = "";
                i++;
                while (i < n && isdigit(formula[i]))
                {
                    mulStr += formula[i];
                    i++;
                }
                i--;
                int mul = mulStr.empty() ? 1 : stoi(mulStr);
                for (auto& [str, cnt] : top)
                {
                    stk.top()[str] += cnt * mul;
                }
            }
            else if (isdigit(formula[i]))
            {
                num += formula[i];
            }
        }
        if (!cur.empty())
        {
            int cnt = num.empty() ? 1 : stoi(num);
            stk.top()[cur] += cnt;
        }
        map<string, int> mp = stk.top();
        string ans = "";
        for (auto& [str, cnt] : mp)
        {
            ans += str;
            if (cnt > 1)
            {
                ans += to_string(cnt);
            }
        }
        return ans;
    }
};
