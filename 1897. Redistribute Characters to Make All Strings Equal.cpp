#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string>& words)
    {
        int list[26]={0};
        for(string& s:words)
        {
            for(char c:s)
            {
                list[c-'a']++;
            }
        }
        int n=(int)words.size();
        for(int i=0;i<26;i++)
        {
            if(list[i]%n)
            {
                return false;
            }
        }
        return true;
    }
};
