#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char kthCharacter(int k)
    {
        string cur="a";
        while(cur.size()<k)
        {
            string temp=cur;
            for(char& c:temp)
            {
                c=(c-'a'+1)%26+'a';
            }
            cur+=temp;
        }
        return cur[k-1];
    }
};
