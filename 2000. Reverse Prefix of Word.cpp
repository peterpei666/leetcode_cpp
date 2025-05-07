#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int len=(int)word.size(),n;
        for(n=0;n<len;n++)
        {
            if(ch==word[n])
            {
                break;
            }
        }
        if(n==len)
        {
            return word;
        }
        for(int i=0;i<=n/2;i++)
        {
            swap(word[i],word[n-i]);
        }
        return word;
    }
};
