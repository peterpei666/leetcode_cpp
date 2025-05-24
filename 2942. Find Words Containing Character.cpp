#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string>& words, char x)
    {
        vector<int> ret;
        for(int i=0;i<words.size();i++)
        {
            for(char c:words[i])
            {
                if(c==x)
                {
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};
