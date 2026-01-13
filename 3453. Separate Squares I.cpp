#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    double total;
    int n;
    
    bool check(double y, vector<vector<int>>& squares)
    {
        double area = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (squares[i][1] < y)
            {
                area += squares[i][2] * min(y - squares[i][1], squares[i][2] * 1.0);
            }
        }
        return area >= total / 2;
    }
    
public:
    double separateSquares(vector<vector<int>>& squares)
    {
        n = (int)squares.size();
        total = 0.0;
        double l = 0, r = 1.5e9;
        for (int i = 0; i < n; i++)
        {
            total += 1.0 * squares[i][2] * squares[i][2];
        }
        while (r - l > 1e-5)
        {
            double mid = (l + r) / 2;
            if (check(mid, squares))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
};
