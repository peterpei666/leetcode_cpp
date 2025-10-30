#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<string> split(const string& s, const string& delimiter)
    {
        vector<string> tokens;
        size_t start = 0;
        size_t end = s.find(delimiter);
        while (end != string::npos)
        {
            tokens.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
            end = s.find(delimiter, start);
        }
        tokens.push_back(s.substr(start));
        return tokens;
    }
    
public:
    string simplifyPath(const string& path)
    {
        vector<string> words = split(path, "/");
        vector<string> ans;
        for (auto& w : words)
        {
            if (w == "..")
            {
                if (!ans.empty())
                {
                    ans.pop_back();
                }
                continue;
            }
            if (w == "" || w == ".")
            {
                continue;
            }
            ans.push_back("/" + w);
        }
        if (ans.empty())
        {
            return "/";
        }
        string s = "";
        for (auto& w : ans)
        {
            s += w;
        }
        return s;
    }
};
