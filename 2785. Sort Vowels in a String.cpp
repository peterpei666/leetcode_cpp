#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    
    inline bool is_vowel(char c)
    {
        for (int i = 0; i < 5; i++)
        {
            if (c == v[i] || c - 'A' + 'a' == v[i])
            {
                return true;
            }
        }
        return false;
    }
    
public:
    string sortVowels(string s)
    {
        vector<char> vowel;
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (is_vowel(s[i]))
            {
                vowel.push_back(s[i]);
                s[i] = '*';
            }
        }
        sort(vowel.begin(), vowel.end());
        for (int i = 0, j = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                s[i] = vowel[j];
                j++;
            }
        }
        return s;
    }
};
