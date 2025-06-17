#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int,int> list;
    
    Solution()
    {
        list[0]=0;
        list[1]=1;
    }
    
    int minDays(int n)
    {
        if(list.count(n))
        {
            return list[n];
        }
        list[n]=1+min(n%2+minDays(n/2),n%3+minDays(n/3));
        return list[n];
    }
};
