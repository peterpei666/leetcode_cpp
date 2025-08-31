#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends)
    {
        int ord[101] = {0};
        int n = (int)order.size();
        for (int i = 0; i < n; i++)
        {
            ord[order[i]] = i;
        }
        sort(friends.begin(), friends.end(), [&](const int& a, const int& b) { return ord[a] < ord[b]; });
        return friends;
    }
};
