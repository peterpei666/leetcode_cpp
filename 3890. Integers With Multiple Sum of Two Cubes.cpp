#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> ans;
bool ready = false;

void init()
{
    unordered_map<int, int> mp;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            int sum = i * i * i + j * j * j;
            if (sum > 1e9)
            {
                break;
            }
            mp[sum]++;
        }
    }
    for (auto [x, n] : mp)
    {
        if (n >= 2)
        {
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
}

class Solution
{
public:
    vector<int> findGoodIntegers(int n)
    {
        if (!ready)
        {
            init();
            ready = true;
        }
        return vector<int>(ans.begin(), upper_bound(ans.begin(), ans.end(), n));
    }
};
