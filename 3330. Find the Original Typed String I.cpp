#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int possibleStringCount(const string& word)
    {
        int n=(int)word.size();
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(word[i]==word[i-1])
            {
                ans++;
            }
        }
        return ans;
    }
};
