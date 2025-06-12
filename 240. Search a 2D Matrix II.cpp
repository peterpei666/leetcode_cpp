#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for(auto& row:matrix)
        {
            if(row[0]>target||row[row.size()-1]<target)
            {
                continue;
            }
            auto temp=lower_bound(row.begin(),row.end(),target);
            if(temp!=row.end()&&*temp==target)
            {
                return true;
            }
        }
        return false;
    }
};
