#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
public:
    string trimTrailingVowels(const string& s)
    {
        int n = (int)s.size() - 1;
        while (n >= 0 && isVowel(s[n]))
        {
            n--;
        }
        return s.substr(0, n + 1);
    }
};
