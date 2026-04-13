#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<double> internalAngles(vector<int>& sides)
    {
        int a = sides[0], b = sides[1], c = sides[2];
        if (!(a + b > c && a + c > b && b + c > a))
        {
            return {};
        }
        const double pi = 3.1415926535897;
        double a1 = acos((a * a + b * b - c * c) * 1.0 / (2 * a * b)) / pi * 180;
        double a2 = acos((c * c + b * b - a * a) * 1.0 / (2 * c * b)) / pi * 180;
        double a3 = acos((a * a + c * c - b * b) * 1.0 / (2 * a * c)) / pi * 180;
        vector<double> ans = {a1, a2, a3};
        sort(ans.begin(), ans.end());
        return ans;
    }
};
