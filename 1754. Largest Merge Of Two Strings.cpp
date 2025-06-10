#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestMerge(string word1,string word2)
    {
        string ret;
        while(!word1.empty()&&!word2.empty())
        {
            if(word1>word2)
            {
                ret.push_back(word1[0]);
                word1=word1.substr(1);
            }
            else
            {
                ret.push_back(word2[0]);
                word2=word2.substr(1);
            }
        }
        if(!word1.empty())
        {
            ret+=word1;
        }
        if(!word2.empty())
        {
            ret+=word2;
        }
        return ret;
    }
};
