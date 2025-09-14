#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    static inline string lower(string s)
    {
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
    
    static inline string vowel(string s)
    {
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                s[i] = '*';
            }
        }
        return s;
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_map<string, string> mp;
        for (auto& s : wordlist)
        {
            mp[s + "#"] = s;
            string s1 = lower(s);
            if (!mp.count(s1))
            {
                mp[s1] = s;
            }
            string s2 = vowel(s1);
            if (!mp.count(s2))
            {
                mp[s2] = s;
            }
        }
        vector<string> ans;
        for (auto& q : queries)
        {
            if (mp.count(q + "#"))
            {
                ans.push_back(q);
                continue;
            }
            string s1 = lower(q);
            if (mp.count(s1))
            {
                ans.push_back(mp[s1]);
                continue;
            }
            string s2 = vowel(s1);
            if (mp.count(s2))
            {
                ans.push_back(mp[s2]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
