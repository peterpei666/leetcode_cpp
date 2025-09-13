#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    stack<string> stk;
    bool tag = false;
    
    bool valid_tag_name(const string& s, bool ending)
    {
        if (s.size() < 1 || s.size() > 9)
        {
            return false;
        }
        for (char c : s)
        {
            if (!(c >= 'A' && c <= 'Z'))
            {
                return false;
            }
        }
        if (ending)
        {
            if (!stk.empty() && stk.top() == s)
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            tag = true;
            stk.push(s);
        }
        return true;
    }
    
    static inline bool valid_cdata(const string& s)
    {
        return s.rfind("[CDATA[", 0) == 0;
    }
    
public:
    bool isValid(const string& code)
    {
        if (code.empty() || code[0] != '<' || code.back() != '>')
        {
            return false;
        }
        int n = (int)code.size();
        for (int i = 0; i < n; i++)
        {
            bool ending = false;
            int close_idx;
            if (stk.empty() && tag)
            {
                return false;
            }
            if (code[i] == '<')
            {
                if (!stk.empty() && i + 1 < n && code[i + 1] == '!')
                {
                    close_idx = (int)code.find("]]>", i + 1);
                    if (close_idx == string::npos || !valid_cdata(code.substr(i + 2, close_idx - (i + 2))))
                    {
                        return false;
                    }
                }
                else
                {
                    if (i + 1 < n && code[i + 1] == '/')
                    {
                        i++;
                        ending = true;
                    }
                    close_idx = (int)code.find('>', i + 1);
                    if (close_idx == string::npos || !valid_tag_name(code.substr(i + 1, close_idx - (i + 1)), ending))
                    {
                        return false;
                    }
                }
                i = close_idx;
            }
        }
        return stk.empty() && tag;
    }
};
