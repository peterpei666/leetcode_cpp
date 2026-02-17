#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<string>> ans;
    
public:
    Solution()
    {
        ans.resize(11);
        int bit[60];
        for (int i = 0; i < 60; i++)
        {
            bit[i] = __builtin_popcount(i);
        }
        for (int i = 0; i < 11; i++)
        {
            for (int h = 0; h < 12; h++)
            {
                int rem = i - bit[h];
                if (rem >= 0)
                {
                    for (int m = 0; m < 10; m++)
                    {
                        if (rem == bit[m])
                        {
                            ans[i].push_back(to_string(h) + ":0" + to_string(m));
                        }
                    }
                    for (int m = 10; m < 60; m++)
                    {
                        if (rem == bit[m])
                        {
                            ans[i].push_back(to_string(h) + ":" + to_string(m));
                        }
                    }
                }
            }
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn)
    {
        return ans[turnedOn];
    }
};
