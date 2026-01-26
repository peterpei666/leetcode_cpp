#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int n = (int)arr.size();
        int dif = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            dif = min(dif, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] == dif)
            {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
